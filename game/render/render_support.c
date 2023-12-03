/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_support.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:04:06 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/03 15:07:50 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_box(t_game *game, t_collider *coll)
{
	int	x;
	int	y;
	int x_b;
	int y_b;

	x = 0;
	y = 0;
	while (x < coll->width)
	{
		y = 0;
		while (y < coll->height)
		{
			if (!(x != 0 && x != coll->width - 1 && y != 0 && y != coll->height - 1))
			{
				x_b = *coll->x + coll->align_top + x;
				y_b = *coll->y + coll->align_left+ y;
				mlx_pixel_put(game->mlx, game->window, x_b, y_b, 0b111100001111000000111110);
			}
			y++;
		}
		x++;
	}
}

void	render_colliders(t_game *game)
{
	t_scene *scene;
	int		coll_ctn;
	
	scene = game->scene;
	coll_ctn = 0;
	while(scene->objs[coll_ctn])
	{
		draw_box(game, scene->objs[coll_ctn]->coll);
		coll_ctn++;
	}
	coll_ctn = 0;
	while(scene->enemies[coll_ctn])
	{
		draw_box(game, scene->enemies[coll_ctn]->coll);
		coll_ctn++;
	}
	draw_box(game, game->player->coll);
}

void	render_hit_box(t_game *game)
{
	t_scene *scene;
	int		coll_ctn;
	
	scene = game->scene;
	coll_ctn = 0;
	while(scene->enemies[coll_ctn])
	{
		draw_box(game, scene->enemies[coll_ctn]->hit_box);
		coll_ctn++;
	}
	draw_box(game, game->player->hit_box);
}