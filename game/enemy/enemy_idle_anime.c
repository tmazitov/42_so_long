/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_idle_anime.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:10:24 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/25 19:27:03 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

t_anime	*make_right_idle_anime(void *mlx, int height, int width)
{
	char	*tilePaths[5];

	tilePaths[0] = "textures/enemy/idle-right/tile000.xpm";
	tilePaths[1] = "textures/enemy/idle-right/tile001.xpm";
	tilePaths[2] = "textures/enemy/idle-right/tile002.xpm";
	tilePaths[3] = "textures/enemy/idle-right/tile003.xpm";
	tilePaths[4] = NULL;
	return make_anime(mlx, tilePaths, height, width, 9);
}

t_anime	*make_left_idle_anime(void *mlx, int height, int width)
{
	char	*tilePaths[5];

	tilePaths[0] = "textures/enemy/idle-left/tile000.xpm";
	tilePaths[1] = "textures/enemy/idle-left/tile001.xpm";
	tilePaths[2] = "textures/enemy/idle-left/tile002.xpm";
	tilePaths[3] = "textures/enemy/idle-left/tile003.xpm";
	tilePaths[4] = NULL;
	return make_anime(mlx, tilePaths, height, width, 9);
}