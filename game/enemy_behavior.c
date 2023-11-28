/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:48:34 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/28 13:25:46 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"


static t_point_list	*make_path(t_player *player, t_scene *scene, t_enemy *enemy)
{
	t_a_point	*src;
	t_a_point	*dest;

	if (player->current_task || enemy->current_task)
		return (NULL);
	enemy->path_counter++;
	if (enemy->path_counter != PATH_FOUND_CALLDOWN) 
		return (NULL);	
	src = make_a_point(enemy->x, enemy->y, NULL);
	if (!src)
		return (NULL);
	dest = make_a_point(player->x, player->y, NULL);
	if (!dest)
		return (free_a_point(src));
	if (enemy->path)
		free_point_list(enemy->path);
	enemy->path = calc_path(src, dest, scene->game_objs_points);
	free_a_point(src);
	free_a_point(dest);
	enemy->path_counter = 0;
	return (enemy->path);
}



t_anime	*exec_enemy_behavior(t_player *player, t_scene *scene, t_enemy *enemy)
{
	t_point_list	*path;

	if (!player || !scene || !enemy)
		return (NULL);
	if (enemy->current_task)
		return (proc_enemy_task(enemy));
	path = make_path(player, scene, enemy);
	if (!path)
		return (proc_enemy_task(enemy));
	add_enemy_task(enemy);
	return (proc_enemy_task(enemy));
}

