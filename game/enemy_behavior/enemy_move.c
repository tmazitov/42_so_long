/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:08:42 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 18:53:13 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy_behavior.h"

static void	calc_future_path(t_player *player, t_scene *scene, t_enemy *enemy)
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

t_anime	*enemy_handle_move(t_player *player, t_scene *scene, t_enemy *enemy)
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
		return (enemy_idle_anime(enemy));
	target = get_next_point(enemy->path);
	add_enemy_task(enemy, target);
	enemy->path_counter = PATH_FOUND_CALLDOWN;
	return (proc_enemy_task(enemy));
}
