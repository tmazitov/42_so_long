/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:22:38 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/07 13:31:37 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_exit	*make_exit(int x, int y)
{
	t_exit	*exit;

	exit = malloc(sizeof(t_exit));
	if (!exit)
		return (NULL);
	exit->x = x;
	exit->y = y;
	exit->obj = make_scene_obj(OBJ_EXIT, NULL, x, y);
	if (!exit->obj)
		return (free_exit(exit));
	exit->obj->is_render = 0;
	return (exit);
}

void	*free_exit(t_exit *exit)
{
	if (!exit)
		return (NULL);
	if (exit->obj)
		free_scene_obj(exit->obj);
	free(exit);
	return (NULL);
}