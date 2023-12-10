/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_road.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:08:39 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:15:18 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static t_step	calc_step(t_point_node *from, t_point_node *to)
{
	if (!from || !to)
		return (TO_NONE);
	if (to->point->x > from->point->x)
		return (TO_RIGHT);
	if (to->point->x < from->point->x)
		return (TO_LEFT);
	if (to->point->y > from->point->y)
		return (TO_BOT);
	if (to->point->y < from->point->y)
		return (TO_TOP);
	return (TO_NONE);
}

static t_image	*get_road_tile(t_scene *s, t_point_node *point,
		t_point_node *prev)
{
	t_step	prev_step;
	t_step	next_step;

	prev_step = calc_step(prev, point);
	next_step = calc_step(point, point->next);
	if (prev_step == TO_NONE)
		return (get_start_tile(next_step, s));
	if (next_step == TO_NONE)
		return (get_end_tile(prev_step, s));
	if (next_step == prev_step)
		return (get_tile(prev_step, s));
	if ((prev_step == TO_TOP && next_step == TO_RIGHT) || (prev_step == TO_LEFT
			&& next_step == TO_BOT))
		return (s->textures->roads[ROAD_TOP_RIGHT]);
	if ((prev_step == TO_TOP && next_step == TO_LEFT) || (prev_step == TO_RIGHT
			&& next_step == TO_BOT))
		return (s->textures->roads[ROAD_TOP_LEFT]);
	if ((prev_step == TO_BOT && next_step == TO_RIGHT) || (prev_step == TO_LEFT
			&& next_step == TO_TOP))
		return (s->textures->roads[ROAD_BOT_RIGHT]);
	if ((prev_step == TO_BOT && next_step == TO_LEFT) || (prev_step == TO_RIGHT
			&& next_step == TO_TOP))
		return (s->textures->roads[ROAD_BOT_LEFT]);
	return (NULL);
}

static void	render_tile(t_image *image, t_a_point *point, t_game *game)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	x = point->x;
	y = point->y;
	mlx = game->mlx;
	win = game->window;
	mlx_put_image_to_window(mlx, win, image->content, x, y + 16);
}

void	render_player_road(t_game *game)
{
	t_path			*road;
	t_point_node	*point;
	t_point_node	*prev;
	t_image			*image;

	if (!game->scene->player_way)
		return ;
	road = game->scene->player_way;
	prev = NULL;
	point = road->point_list->points;
	while (point)
	{
		image = get_road_tile(game->scene, point, prev);
		if (image)
			render_tile(image, point->point, game);
		prev = point;
		point = point->next;
	}
}
