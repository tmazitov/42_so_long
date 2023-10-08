/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:32:02 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/08 19:30:12 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene_textures	*make_scene_textures(void *mlx)
{
	t_scene_textures	*textures;
	int					height;
	int					width;

	height = 128;
	width = 128;
	textures = malloc(sizeof(t_scene_textures));
	if (!textures)
		return (NULL);
	textures->grass = mlx_xpm_file_to_image(mlx, "textures/grass_3.xpm", &width, &height);
	if (!textures->grass)
		return (free(textures), NULL);
	return (textures);
}

void	*free_scene(t_scene *scene)
{
	free(scene);
	return (NULL);
}

t_scene *make_scene(void *mlx, int height, int width)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->textures = make_scene_textures(mlx);
	if (!scene->textures)
		return (free_scene(scene), NULL);
	scene->height = height;
	scene->width = width;
	printf("feel tree :%d\n",feel_tree(mlx, scene, 1));
	if (feel_tree(mlx, scene, 2) != 0)
		return (free_scene(scene), NULL);
	return (scene);
}