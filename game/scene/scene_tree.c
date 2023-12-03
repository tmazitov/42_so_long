/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:17:07 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/03 19:07:54 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_image	*get_tree_image(t_obj_type t, t_scene *scene)
{
	if (t == OBJ_SHRUB)
		return (scene->textures->shrub);
	else if (t == OBJ_TREE)
		return (scene->textures->tree);
	return (NULL);
}

t_scene_obj	*make_tree(t_scene *scene, int is_border, int x, int y)
{
	t_image		*image;
	t_obj_type	t;
	
	if (is_border)
		t = OBJ_TREE;
	else 
		t = OBJ_SHRUB;
	image = get_tree_image(t, scene);
	if (!image)
		return (NULL);
	return (make_scene_obj(t, image->content, 64*x, 64*y + 64));
}