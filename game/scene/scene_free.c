/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:13:28 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/03 19:20:59 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	*free_scene_enemies(t_enemy **enemies)
{
	int	counter;

	counter = 0;
	while(enemies[counter])
	{
		free_enemy(enemies[counter]);
		counter++;
	}
	free(enemies);
	return (NULL);
}

static void	*free_scene_chests(t_chest **chests)
{
	int	counter;

	counter = 0;
	while(chests[counter])
	{
		free_chest(chests[counter]);
		counter++;
	}
	free(chests);
	return (NULL);
}

static void	*free_scene_objs(t_scene_obj **objs)
{
	int	counter;

	counter = 0;
	while(objs[counter])
	{
		free_scene_obj(objs[counter]);
		counter++;
	}
	free(objs);
	return (NULL);
}

void	*free_scene(t_scene *scene)
{
	if (scene->textures)
		free_scene_textures(scene->textures);
	if (scene->chests)
		free_scene_chests(scene->chests);
	if (scene->enemies)
		free_scene_enemies(scene->enemies);
	if (scene->objs)
		free_scene_objs(scene->objs);
	if (scene->game_objs_points)
		free_point_list(scene->game_objs_points);
	free(scene);
	return (NULL);
}