/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_variants.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:23:06 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 23:31:26 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"

int	inter_straight(t_collider *col1, t_collider *col2, int speed)
{
	t_point	*target_p1;
	t_point	*target_p2;

	sync_collider(col1);
	sync_collider(col2);
	shift_collider(col1, speed, 0);
	target_p1 = col2->top_l;
	target_p2 = col2->bot_l;
	return (inter_segm(col1->top_l, col1->bot_r, target_p1, target_p2)
		&& inter_segm(col1->top_r, col1->bot_l, target_p1, target_p2));
}

int	inter_back(t_collider *col1, t_collider *col2, int speed)
{
	t_point	*target_p1;
	t_point	*target_p2;

	sync_collider(col1);
	sync_collider(col2);
	shift_collider(col1, speed * (-1), 0);
	target_p1 = col2->top_r;
	target_p2 = col2->bot_r;
	return (inter_segm(col1->top_l, col1->bot_r, target_p1, target_p2)
		&& inter_segm(col1->top_r, col1->bot_l, target_p1, target_p2));
}

int	inter_up(t_collider *col1, t_collider *col2, int speed)
{
	t_point	*target_p1;
	t_point	*target_p2;

	sync_collider(col1);
	sync_collider(col2);
	shift_collider(col1, 0, speed);
	target_p1 = col2->top_l;
	target_p2 = col2->top_r;
	return (inter_segm(col1->top_l, col1->bot_r, target_p1, target_p2)
		&& inter_segm(col1->top_r, col1->bot_l, target_p1, target_p2));
}

int	inter_down(t_collider *col1, t_collider *col2, int speed)
{
	t_point	*target_p1;
	t_point	*target_p2;

	sync_collider(col1);
	sync_collider(col2);
	shift_collider(col1, 0, speed * (-1));
	target_p1 = col2->bot_l;
	target_p2 = col2->bot_r;
	return (inter_segm(col1->top_l, col1->bot_r, target_p1, target_p2)
		&& inter_segm(col1->top_r, col1->bot_l, target_p1, target_p2));
}

int	inter_here(t_collider *col1, t_collider *col2)
{
	t_point	*target_p1;
	t_point	*target_p2;
	int		shift;

	shift = col2->height / 2;
	sync_collider(col1);
	coll_upd_bot_left(col2, *col2->x, *col2->y + shift);
	coll_upd_bot_right(col2, *col2->x + col2->width, *col2->y + shift);
	target_p1 = col2->bot_l;
	target_p2 = col2->bot_r;
	return (inter_segm(col1->top_l, col1->bot_r, target_p1, target_p2)
		&& inter_segm(col1->top_r, col1->bot_l, target_p1, target_p2));
}
