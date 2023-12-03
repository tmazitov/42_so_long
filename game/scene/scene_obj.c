/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:54:57 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/03 16:56:38 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene_obj	*make_scene_obj(t_obj_type t, void *image, int x, int y)
{
	t_scene_obj	*obj;

	obj = malloc(sizeof(t_scene_obj));
	if (!obj)
		return (NULL);
	obj->image = image;
	obj->x = x;
	obj->y = y;
	obj->height = 64;
	obj->width = 64;
	obj->type = t;
	obj->coll = make_collider(64, 64, &obj->x, &obj->y);
	if (!obj->coll)
		return (free(obj), NULL);
	obj->is_render = 1;
	return (obj);
}

void	*free_scene_obj(t_scene_obj *obj)
{
	if (!obj)
		return (NULL);
	if (obj->coll)
		free_collider(obj->coll);
	free(obj);
	return (NULL);
}
