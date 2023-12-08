/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_die_anime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:04:35 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/08 16:03:13 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

t_anime	*make_die_anime(void *mlx, int height, int width)
{
	char	*tilePaths[6];

	tilePaths[0] = "textures/enemy/death/tile028.xpm";
	tilePaths[1] = "textures/enemy/death/tile029.xpm";
	tilePaths[2] = "textures/enemy/death/tile030.xpm";
	tilePaths[3] = "textures/enemy/death/tile031.xpm";
	tilePaths[4] = "textures/enemy/death/tile032.xpm";
	tilePaths[5] = NULL;
	return make_anime(mlx, tilePaths, height, width, 6);
}

t_anime	*make_died_anime(void *mlx, int height, int width)
{
	char	*tilePaths[2];

	tilePaths[0] = "textures/enemy/death/tile032.xpm";
	tilePaths[1] = NULL;
	return make_anime(mlx, tilePaths, height, width, 6);
}