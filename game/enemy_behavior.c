/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:48:34 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/02 15:25:36 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void calc_future_path(t_player *player, t_scene *scene, t_enemy *enemy)
{
	t_a_point	*src;
	t_a_point	*dest;

	src = make_a_point(enemy->x, enemy->y, NULL);
	if (!src)
		return ;
	dest = make_a_point(player->last_x, player->last_y, NULL);
	if (!dest)
		return ;
	if (enemy->path)
		free_path(enemy->path);
	enemy->path = calc_path(src, dest, scene->game_objs_points);
	free_a_point(src);
	free_a_point(dest);
	return ;
}

static	int	enemy_delay(t_enemy *enemy)
{
	enemy->path_counter++;
	if (enemy->path_counter < PATH_FOUND_CALLDOWN) 
		return (1);	
	else if (enemy->path_counter >= PATH_FOUND_CALLDOWN)
		enemy->path_counter = 0;
	return (0);
}

static t_anime *handle_move(t_player *player, t_scene *scene, t_enemy *enemy)
{
	t_a_point	*target;

	if (enemy->player_score != player->score)
		enemy->path = free_path(enemy->path);
	if (enemy->path && !enemy->current_task)
	{
		target = get_next_point(enemy->path);
		if (!target)
			enemy->path = free_path(enemy->path);
		else
			add_enemy_task(enemy, target);
	}
	enemy->player_score = player->score;
	if (enemy->current_task)
		return (proc_enemy_task(enemy));
	if (!enemy->path)
		calc_future_path(player, scene, enemy);
	if (!enemy->path)
		return (proc_enemy_task(enemy));
	target = get_next_point(enemy->path);
	add_enemy_task(enemy, target);
	enemy->path_counter = PATH_FOUND_CALLDOWN;
	return (proc_enemy_task(enemy));
}

static t_anime	*handle_die(t_enemy *enemy)
{
	// printf("%p died!\n", enemy);
	if (enemy->current_task && 
		enemy->current_task->action != E_DIE)
		enemy->current_task = free_enemy_task(enemy->current_task);
	if (enemy->is_died && !enemy->anime->die_anime_done)
		add_enemy_task(enemy, NULL);
	if (enemy->is_died && enemy->anime->die_anime_done)
		return (enemy->anime->died);
	return (proc_enemy_task(enemy));
}

t_anime	*exec_enemy_behavior(t_player *player, t_scene *scene, t_enemy *enemy)
{
	t_anime	*anime;

	if (!player || !scene || !enemy)
		return (NULL);
	if (enemy->is_died)
		return (handle_die(enemy));
	if (enemy_is_able_to_move(enemy, scene, player) != 1)
		return (enemy_idle_anime(enemy));
	if (enemy_delay(enemy) != 0 || 
		(enemy->x == player->last_x && enemy->y == player->last_y))
		return (proc_enemy_task(enemy));
	anime = handle_move(player, scene, enemy);
	if (anime)
		return (anime);
	return (proc_enemy_task(enemy));
}

