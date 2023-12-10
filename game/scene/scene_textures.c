/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:41:02 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:21:34 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static int	feel_scene_textures(void *mlx, t_scene_textures *t)
{
	t->grass = make_image_v2(mlx, "textures/grass.xpm");
	if (!t->grass)
		return (1);
	t->tree = make_image_v2(mlx, "textures/tree/tree_4.xpm");
	if (!t->tree)
		return (1);
	t->shrub = make_image_v2(mlx, "textures/tree/tree_2.xpm");
	if (!t->shrub)
		return (1);
	if (make_road_textures(mlx, t) != 0)
		return (1);
	return (0);
}

static void	init_scene_textures(t_scene_textures *t)
{
	t->grass = NULL;
	t->shrub = NULL;
	t->roads = NULL;
	t->tree = NULL;
}

t_scene_textures	*make_scene_textures(void *mlx)
{
	t_scene_textures	*textures;

	textures = malloc(sizeof(t_scene_textures));
	if (!textures)
		return (NULL);
	init_scene_textures(textures);
	if (feel_scene_textures(mlx, textures) != 0)
		return (free_scene_textures(textures));
	return (textures);
}

void	*free_scene_textures(t_scene_textures *t)
{
	int	counter;

	if (!t)
		return (NULL);
	if (t->grass)
		free_image(t->grass);
	if (t->tree)
		free_image(t->tree);
	if (t->shrub)
		free_image(t->shrub);
	if (t->roads)
	{
		counter = 0;
		while (t->roads[counter])
			free_image(t->roads[counter++]);
		free(t->roads);
	}
	free(t);
	return (NULL);
}
