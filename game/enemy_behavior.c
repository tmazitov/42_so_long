/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:48:34 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/26 21:42:31 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"


void	exec_enemy_behavior(t_player *player, t_scene *scene, t_enemy *enemy)
{
	// TODO : Make the fast calc of the way to the player
	// and record the steps of new way
	
	// The first step have a reason to return the animation
	
	// TODO : Make the same structure like player_task for the enemy
	t_a_point	*src;
	t_a_point	*dest;
	if (player->current_task)
		return ;
	if (enemy->path_counter != PATH_FOUND_CALLDOWN) 
	{
		enemy->path_counter++;
		return;	
	}

	src = make_a_point(enemy->x, enemy->y, NULL);
	if (!src)
		return ;
	dest = make_a_point(player->x, player->y, NULL);
	if (!dest)
		return ;
	if (enemy->path)
		free_point_list(enemy->path);
	enemy->path = calc_path(src, dest, scene->game_objs_points);
	// printf("enemy path: %p\n", enemy->path);
	enemy->path_counter = 0;
}