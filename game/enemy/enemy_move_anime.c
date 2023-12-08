/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_anime.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:21:13 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/08 16:06:38 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

t_anime	*make_right_move_anime(void *mlx, int height, int width)
{
	char	*tilePaths[9];

	tilePaths[0] = "textures/enemy/move-right/tile007.xpm";
	tilePaths[1] = "textures/enemy/move-right/tile008.xpm";
	tilePaths[2] = "textures/enemy/move-right/tile008_1.xpm";
	tilePaths[3] = "textures/enemy/move-right/tile009.xpm";
	tilePaths[4] = "textures/enemy/move-right/tile009_1.xpm";
	tilePaths[5] = "textures/enemy/move-right/tile010.xpm";
	tilePaths[6] = "textures/enemy/move-right/tile011.xpm";
	tilePaths[7] = "textures/enemy/move-right/tile012.xpm";
	tilePaths[8] = NULL;
	return make_anime(mlx, tilePaths, height, width, 8);
}

t_anime	*make_left_move_anime(void *mlx, int height, int width)
{
	char	*tilePaths[9];

	tilePaths[0] = "textures/enemy/move-left/tile007.xpm";
	tilePaths[1] = "textures/enemy/move-left/tile008.xpm";
	tilePaths[2] = "textures/enemy/move-left/tile008_1.xpm";
	tilePaths[3] = "textures/enemy/move-left/tile009.xpm";
	tilePaths[4] = "textures/enemy/move-left/tile009_1.xpm";
	tilePaths[5] = "textures/enemy/move-left/tile010.xpm";
	tilePaths[6] = "textures/enemy/move-left/tile011.xpm";
	tilePaths[7] = "textures/enemy/move-left/tile012.xpm";
	tilePaths[8] = NULL;
	return make_anime(mlx, tilePaths, height, width, 8);
}