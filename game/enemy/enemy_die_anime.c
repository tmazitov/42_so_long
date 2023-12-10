/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_die_anime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:04:35 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:40:20 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

t_anime	*make_die_anime(void *mlx)
{
	char	*tile_paths[6];

	tile_paths[0] = "textures/enemy/death/tile028.xpm";
	tile_paths[1] = "textures/enemy/death/tile029.xpm";
	tile_paths[2] = "textures/enemy/death/tile030.xpm";
	tile_paths[3] = "textures/enemy/death/tile031.xpm";
	tile_paths[4] = "textures/enemy/death/tile032.xpm";
	tile_paths[5] = NULL;
	return (make_anime(mlx, tile_paths, 4));
}

t_anime	*make_died_anime(void *mlx)
{
	char	*tile_paths[2];

	tile_paths[0] = "textures/enemy/death/tile032.xpm";
	tile_paths[1] = NULL;
	return (make_anime(mlx, tile_paths, 4));
}
