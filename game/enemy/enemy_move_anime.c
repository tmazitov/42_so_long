/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_anime.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:21:13 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:40:59 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

t_anime	*make_right_move_anime(void *mlx)
{
	char	*tile_paths[9];

	tile_paths[0] = "textures/enemy/move-right/tile007.xpm";
	tile_paths[1] = "textures/enemy/move-right/tile008.xpm";
	tile_paths[2] = "textures/enemy/move-right/tile008_1.xpm";
	tile_paths[3] = "textures/enemy/move-right/tile009.xpm";
	tile_paths[4] = "textures/enemy/move-right/tile009_1.xpm";
	tile_paths[5] = "textures/enemy/move-right/tile010.xpm";
	tile_paths[6] = "textures/enemy/move-right/tile011.xpm";
	tile_paths[7] = "textures/enemy/move-right/tile012.xpm";
	tile_paths[8] = NULL;
	return (make_anime(mlx, tile_paths, 4));
}

t_anime	*make_left_move_anime(void *mlx)
{
	char	*tile_paths[9];

	tile_paths[0] = "textures/enemy/move-left/tile007.xpm";
	tile_paths[1] = "textures/enemy/move-left/tile008.xpm";
	tile_paths[2] = "textures/enemy/move-left/tile008_1.xpm";
	tile_paths[3] = "textures/enemy/move-left/tile009.xpm";
	tile_paths[4] = "textures/enemy/move-left/tile009_1.xpm";
	tile_paths[5] = "textures/enemy/move-left/tile010.xpm";
	tile_paths[6] = "textures/enemy/move-left/tile011.xpm";
	tile_paths[7] = "textures/enemy/move-left/tile012.xpm";
	tile_paths[8] = NULL;
	return (make_anime(mlx, tile_paths, 4));
}
