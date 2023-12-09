/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_textures_roads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:18:21 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/09 18:42:24 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	init_roads(void *mlx, t_image **storage)
{
	storage[0] = make_image_v2(mlx, "texture/roads/til000.xpm");
	storage[1] = make_image_v2(mlx, "texture/roads/til001.xpm");
	storage[2] = make_image_v2(mlx, "texture/roads/til002.xpm");
	storage[3] = make_image_v2(mlx, "texture/roads/til003.xpm");
	storage[4] = make_image_v2(mlx, "texture/roads/til004.xpm");
	storage[5] = make_image_v2(mlx, "texture/roads/til005.xpm");
	storage[6] = make_image_v2(mlx, "texture/roads/til006.xpm");
	storage[7] = make_image_v2(mlx, "texture/roads/til007.xpm");
	storage[8] = make_image_v2(mlx, "texture/roads/til008.xpm");
	storage[9] = make_image_v2(mlx, "texture/roads/til009.xpm");
	storage[10] = make_image_v2(mlx, "texture/roads/til010.xpm");
	storage[11] = make_image_v2(mlx, "texture/roads/til011.xpm");
	storage[12] = make_image_v2(mlx, "texture/roads/til012.xpm");
	storage[13] = make_image_v2(mlx, "texture/roads/til013.xpm");
	storage[14] = make_image_v2(mlx, "texture/roads/til014.xpm");
	storage[15] = make_image_v2(mlx, "texture/roads/til015.xpm");
	storage[16] = make_image_v2(mlx, "texture/roads/til016.xpm");
	storage[17] = make_image_v2(mlx, "texture/roads/til017.xpm");
	storage[18] = make_image_v2(mlx, "texture/roads/til018.xpm");
	storage[19] = make_image_v2(mlx, "texture/roads/til019.xpm");
	storage[20] = make_image_v2(mlx, "texture/roads/til020.xpm");
	storage[21] = make_image_v2(mlx, "texture/roads/til021.xpm");
	storage[22] = NULL;
}

int	make_road_textures(void *mlx, t_scene_textures *t)
{
	int	counter;

	t->roads = malloc(sizeof(t_image) * 23);
	if (!t->roads)
		return (1);
	init_roads(mlx, t->roads);
	counter = 0;
	while (t->roads[counter]) 
		counter++;
	return (counter != 22);
}