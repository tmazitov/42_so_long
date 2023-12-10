/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:22:38 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/11 03:03:27 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	init_exit_inst(t_exit *exit)
{
	exit->image = NULL;
	exit->obj = NULL;
}

t_exit	*make_exit(void *mlx, int x, int y)
{
	t_exit	*exit;

	exit = malloc(sizeof(t_exit));
	if (!exit)
		return (NULL);
	init_exit_inst(exit);
	exit->x = x;
	exit->y = y;
	exit->obj = make_scene_obj(OBJ_EXIT, NULL, x, y);
	if (!exit->obj)
		return (free_exit(exit));
	exit->obj->is_render = 0;
	exit->image = make_image_v2(mlx, "textures/bed.xpm");
	if (!exit->image)
		return (free_exit(exit));
	return (exit);
}

void	*free_exit(t_exit *exit)
{
	if (!exit)
		return (NULL);
	if (exit->obj)
		free_scene_obj(exit->obj);
	if (exit->image)
		free_image(exit->image);
	free(exit);
	return (NULL);
}
