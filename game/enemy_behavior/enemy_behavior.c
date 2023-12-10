/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:48:34 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/07 13:56:26 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy_behavior.h"

static int	enemy_delay(t_enemy *enemy)
{
	enemy->path_counter++;
	if (enemy->path_counter < PATH_FOUND_CALLDOWN)
		return (1);
	else if (enemy->path_counter >= PATH_FOUND_CALLDOWN)
		enemy->path_counter = 0;
	return (0);
}

static t_anime	*handle_die(t_enemy *enemy)
{
	if (enemy->current_task && enemy->current_task->action != E_DIE)
		enemy->current_task = free_enemy_task(enemy->current_task);
	if (enemy->is_died && !enemy->anime->die_anime_done)
		add_enemy_task(enemy, NULL);
	if (enemy->is_died && enemy->anime->die_anime_done)
		return (enemy->anime->died);
	return (proc_enemy_task(enemy));
}

static int	check_intersect_hit_box(t_enemy *enemy, t_player *player)
{
	return (check_intersection(enemy->coll, player->coll, 5, 0));
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
	if (check_intersect_hit_box(enemy, player))
		enemy_handle_attack(enemy, player);
	if (enemy_delay(enemy) != 0 || (enemy->x == player->last_x
			&& enemy->y == player->last_y))
		return (proc_enemy_task(enemy));
	anime = enemy_handle_move(player, scene, enemy);
	if (anime)
		return (anime);
	return (proc_enemy_task(enemy));
}
