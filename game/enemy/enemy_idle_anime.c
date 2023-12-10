/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_idle_anime.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:10:24 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:40:40 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

t_anime	*make_right_idle_anime(void *mlx)
{
	char	*tile_paths[5];

	tile_paths[0] = "textures/enemy/idle-right/tile000.xpm";
	tile_paths[1] = "textures/enemy/idle-right/tile001.xpm";
	tile_paths[2] = "textures/enemy/idle-right/tile002.xpm";
	tile_paths[3] = "textures/enemy/idle-right/tile003.xpm";
	tile_paths[4] = NULL;
	return (make_anime(mlx, tile_paths, 8));
}

t_anime	*make_left_idle_anime(void *mlx)
{
	char	*tile_paths[5];

	tile_paths[0] = "textures/enemy/idle-left/tile000.xpm";
	tile_paths[1] = "textures/enemy/idle-left/tile001.xpm";
	tile_paths[2] = "textures/enemy/idle-left/tile002.xpm";
	tile_paths[3] = "textures/enemy/idle-left/tile003.xpm";
	tile_paths[4] = NULL;
	return (make_anime(mlx, tile_paths, 8));
}

t_anime	*enemy_idle_anime(t_enemy *enemy)
{
	if (enemy->last_action == E_MOVE_BACK)
		return (enemy->anime->idle_left);
	return (enemy->anime->idle_right);
}
