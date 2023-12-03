/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:47:33 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/03 19:11:12 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_scene(t_game *game)
{
	int		x;
	int		y;
	void	*image;

	x = 0;
	image = game->scene->textures->grass->content;
	while (x < game->scene->width)
	{
		y = 0;
		while (y < game->scene->height)
		{
			mlx_put_image_to_window(game->mlx, game->window, image, x, y);
			y += 128;
		}
		x += 128;	
	}
}

static void render_scene_obj(void *mlx, void *win, t_scene_obj *obj)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	
	if (obj->type == OBJ_TREE)
	{
		x = obj->x - (obj->width - obj->coll->width) / 2 - 16;
		y = obj->y - (obj->height - obj->coll->height) / 2 - 64;
	}
	else if (obj->type == OBJ_SHRUB)
	{
		x = obj->x;
		y = obj->y;
	}
	mlx_put_image_to_window(mlx, win, obj->image, x, y);
}

void	render_scene_objs(t_game *game)
{
	int 	counter;
	t_scene_obj	**objs;
	t_scene_obj	*obj;

	counter = 0;

	objs = game->scene->objs;
	while (objs[counter])
	{
		obj = objs[counter];
		if (obj->is_render)
			render_scene_obj(game->mlx, game->window, obj);
		counter++;
	}
}

void	render_chests(t_game *game)
{
	void	*chest_image;
	t_chest	**chests;
	t_chest	*chest;
	int		counter;

	counter = 0;
	chests = game->scene->chests;
	while (chests[counter])
	{
		chest = chests[counter];
		chest_image = render_chest(chest);
		mlx_put_image_to_window(game->mlx, game->window, chest_image, chest->obj->x, chest->obj->y);
		counter++;
	} 
}