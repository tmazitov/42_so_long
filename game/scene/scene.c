/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:32:02 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/08 14:54:45 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

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

static void	init_scene(t_scene *scene)
{
	scene->game_objs_points = NULL;
	scene->textures = NULL;
	scene->chests = NULL;
	scene->enemies = NULL;
	scene->objs = NULL;
	scene->raw = NULL;
	scene->exit = NULL;
	scene->player_x = 0;
	scene->player_y = 0;
	scene->exit_x = 0;
	scene->exit_y = 0;
}

t_scene *make_scene(void *mlx, t_map *map, int height, int width)
{
	t_scene	*scene;
	int		err;
	
	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	init_scene(scene);
	scene->mlx = mlx;
	scene->textures = make_scene_textures(mlx);
	if (!scene->textures)
		return (free_scene(scene));
	scene->height = height;
	scene->width = width;
	err = feel_scene(mlx, map, scene);
	free_map(map);
	if (err != 0)
		return (free_scene(scene));
	scene->game_objs_points = make_game_points(scene);
	if (!scene->game_objs_points)
		return (free_scene(scene));
	scene->exit = make_exit(scene->exit_x, scene->exit_y);
	if (!scene->exit)
		return (free_scene(scene));
	return (scene);
}

