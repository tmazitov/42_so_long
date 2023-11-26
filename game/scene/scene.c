/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:32:02 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/26 20:28:01 by tmazitov         ###   ########.fr       */
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
	textures->grass = mlx_xpm_file_to_image(mlx, "textures/grass.xpm", &width, &height);
	if (!textures->grass)
		return (free(textures), NULL);
	return (textures);
}

void	*free_scene(t_scene *scene)
{
	free(scene);
	return (NULL);
}

static t_point_list	*make_game_points(t_scene *scene)
{
	t_point_list	*result;
	t_a_point		*point;
	t_scene_obj		**objs;
	
	if (!scene)
		return (NULL);
	result = make_point_list();
	if (!result)
		return (NULL);
	objs = scene->objs;
	while (*objs) 
	{
		point = make_a_point((*objs)->x, (*objs)->y, NULL);
		if (lst_add_point(result, point) != 0)
			return (NULL);
		objs++;
	}
	return (result);
}

t_scene *make_scene(void *mlx, char *mapPath, int height, int width)
{
	t_scene	*scene;
	char	**map;

	map = parse(mapPath);
	if (!map)
		return (NULL);
	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->textures = make_scene_textures(mlx);
	if (!scene->textures)
		return (free_scene(scene), NULL);
	scene->height = height;
	scene->width = width;
	// printf("feel tree :%d\n", feel_tree(mlx, scene, 1));
	if (feel_tree(mlx, map, scene) != 0)
		return (free_scene(scene), NULL);
	scene->game_objs_points = make_game_points(scene);
	if (!scene->game_objs_points)
		return (free_scene(scene), NULL);
	printf("success map\n");
	return (scene);
}

