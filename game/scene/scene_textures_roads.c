/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_textures_roads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:18:21 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:21:43 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	init_roads(void *mlx, t_image **storage)
{
	storage[0] = make_image_v2(mlx, "textures/roads/tile000.xpm");
	storage[1] = make_image_v2(mlx, "textures/roads/tile001.xpm");
	storage[2] = make_image_v2(mlx, "textures/roads/tile002.xpm");
	storage[3] = make_image_v2(mlx, "textures/roads/tile003.xpm");
	storage[4] = make_image_v2(mlx, "textures/roads/tile004.xpm");
	storage[5] = make_image_v2(mlx, "textures/roads/tile005.xpm");
	storage[6] = make_image_v2(mlx, "textures/roads/tile006.xpm");
	storage[7] = make_image_v2(mlx, "textures/roads/tile007.xpm");
	storage[8] = make_image_v2(mlx, "textures/roads/tile008.xpm");
	storage[9] = make_image_v2(mlx, "textures/roads/tile009.xpm");
	storage[10] = make_image_v2(mlx, "textures/roads/tile010.xpm");
	storage[11] = make_image_v2(mlx, "textures/roads/tile011.xpm");
	storage[12] = make_image_v2(mlx, "textures/roads/tile012.xpm");
	storage[13] = make_image_v2(mlx, "textures/roads/tile013.xpm");
	storage[14] = make_image_v2(mlx, "textures/roads/tile014.xpm");
	storage[15] = make_image_v2(mlx, "textures/roads/tile015.xpm");
	storage[16] = make_image_v2(mlx, "textures/roads/tile016.xpm");
	storage[17] = make_image_v2(mlx, "textures/roads/tile017.xpm");
	storage[18] = make_image_v2(mlx, "textures/roads/tile018.xpm");
	storage[19] = make_image_v2(mlx, "textures/roads/tile019.xpm");
	storage[20] = make_image_v2(mlx, "textures/roads/tile020.xpm");
	storage[21] = make_image_v2(mlx, "textures/roads/tile021.xpm");
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
	printf("counter : %d\n", counter);
	return (counter != 22);
}
