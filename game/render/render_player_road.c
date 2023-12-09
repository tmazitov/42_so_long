/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_road.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:08:39 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/09 20:19:37 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_step	calc_step(t_a_point *from, t_a_point *to)
{
	if (!from || !to)
		return (-1);
	if (to->x > from->x)
		return (TO_RIGHT);
	if (to->x < from->x)
		return (TO_LEFT);
	if (to->y > from->y)
		return (TO_TOP);
	if (to->y < from->y)
		return (TO_BOT);
	return (-1);
}

t_image	*get_point_tile(t_step next_step, t_scene *s)
{
	if (next_step == TO_BOT)
		return (s->textures->roads[ROAD_NONE_BOT]);
	if (next_step == TO_TOP)
		return (s->textures->roads[ROAD_NONE_TOP]);
	if (next_step == TO_RIGHT)
		return (s->textures->roads[ROAD_NONE_RIGHT]);
	if (next_step == TO_LEFT)
		return (s->textures->roads[ROAD_NONE_LEFT]);
	return (NULL);
}

t_image	*get_tile(t_step next, t_step prev, t_scene *s)
{
	if (prev == TO_BOT && next == TO_BOT ||
		prev == TO_TOP && next == TO_TOP)
		return (s->textures->roads[ROAD_TOP_TOP]);
	if (prev == TO_LEFT && next == TO_LEFT ||
		prev == TO_RIGHT && next == TO_RIGHT)
		return (s->textures->roads[ROAD_RIGHT_RIGHT]);
	return (NULL);
}

t_image	*get_road_tile(t_scene *s, t_point_node *point, t_point_node *prev)
{
	t_step	prev_step;
	t_step	next_step;

	prev_step = calc_step(prev->point, point->point);
	next_step = calc_step(point->point, point->next->point);
	if (prev_step == -1)
		return (get_point_tile(next_step, s));
	if (next_step == -1)
		return (get_point_tile(prev_step, s));
	if (next_step == prev_step)
		return (get_tile(next_step, prev_step, s));
	if (prev_step == TO_TOP && next_step == TO_RIGHT || 
		prev_step == TO_LEFT && next_step == TO_BOT)
		return (s->textures->roads[ROAD_TOP_RIGHT]);
	if (prev_step == TO_TOP && next_step == TO_LEFT ||
		prev_step == TO_RIGHT && next_step == TO_BOT)
		return (s->textures->roads[ROAD_TOP_LEFT]);
	if (prev_step == TO_BOT && next_step == TO_RIGHT ||
		prev_step == TO_LEFT && next_step == TO_TOP)
		return (s->textures->roads[ROAD_BOT_RIGHT]);
	if (prev_step == TO_BOT && next_step == TO_LEFT || 
		prev_step == TO_RIGHT && next_step == TO_TOP)
		return (s->textures->roads[ROAD_BOT_LEFT]);
}

void	render_tile(t_image *image, t_a_point *point, t_game *game)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	x = point->x;
	y = point->y;
	mlx = game->mlx;
	win = game->window;
	mlx_put_image_to_window(mlx, win, image->content, x, y);
}

void	render_player_road(t_game *game)
{
	t_path			*road;
	t_point_node	*point;
	t_point_node	*prev;
	t_image			*image;

	road = game->scene->player_way;
	prev = NULL;
	point = road->point_list->points;
	while (point)
	{
		image = get_road_tile(game->scene, point, prev);
		if (image)
		{
			render_tile(image, point->point, game);	 
		}
		prev = point;
		point = point->next;
	}
}