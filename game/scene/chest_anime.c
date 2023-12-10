/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chest_anime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:20:25 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 23:59:20 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_anime	*make_chest_open_anime(void *mlx)
{
	char	*tile_paths[5];

	tile_paths[0] = "textures/chest/chest_1.xpm";
	tile_paths[1] = "textures/chest/chest_2.xpm";
	tile_paths[2] = "textures/chest/chest_3.xpm";
	tile_paths[3] = "textures/chest/chest_4.xpm";
	tile_paths[4] = NULL;
	return (make_anime(mlx, tile_paths, 5));
}

t_anime	*make_chest_close_anime(void *mlx)
{
	char	*tile_paths[5];

	tile_paths[0] = "textures/chest/chest_4.xpm";
	tile_paths[1] = "textures/chest/chest_3.xpm";
	tile_paths[2] = "textures/chest/chest_2.xpm";
	tile_paths[3] = "textures/chest/chest_1.xpm";
	tile_paths[4] = NULL;
	return (make_anime(mlx, tile_paths, 5));
}
