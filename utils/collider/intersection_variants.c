/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_variants.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:23:06 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/30 12:58:56 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"

int inter_straight(t_collider *col1, t_collider *col2, int speed)
{
	t_point *p1_1;
	t_point *p1_2;
	t_point *p2_1;
	t_point *p2_2;
	t_point *target_p1;
	t_point *target_p2;

	p1_1 = coll_upd_top_left(col1, *col1->x, *col1->y);
	p1_2 = coll_upd_bot_right(col1, *col1->x + col1->width, *col1->y + col1->height);
	p2_1 = coll_upd_top_right(col1, *col1->x + col1->width, *col1->y);
	p2_2 = coll_upd_bot_left(col1, *col1->x, *col1->y + col1->height);
	p1_1 = coll_upd_top_left(col1,  p1_1->x + speed, p1_1->y);
	p1_2 = coll_upd_bot_right(col1, p1_2->x + speed, p1_2->y);
	p2_1 = coll_upd_top_right(col1, p2_1->x + speed, p2_1->y);
	p2_2 = coll_upd_bot_left(col1,  p2_2->x + speed, p2_2->y);
	target_p1 = coll_upd_top_left(col2, *col2->x, *col2->y);
	target_p2 = coll_upd_bot_left(col2, *col2->x, *col2->y + col2->height);
	return (do_line_intersect_segment(*p1_1, *p1_2, *target_p1, *target_p2) &&
			do_line_intersect_segment(*p2_1, *p2_2, *target_p1, *target_p2));
}

int inter_back(t_collider *col1, t_collider *col2, int speed)
{
	t_point *p1_1;
	t_point *p1_2;
	t_point *p2_1;
	t_point *p2_2;
	t_point *target_p1;
	t_point *target_p2;

	p1_1 = coll_upd_top_left(col1, *col1->x, *col1->y);
	p1_2 = coll_upd_bot_right(col1, *col1->x + col1->width, *col1->y + col1->height);
	p2_1 = coll_upd_top_right(col1, *col1->x + col1->width, *col1->y);
	p2_2 = coll_upd_bot_left(col1, *col1->x, *col1->y + col1->height);
	p1_1 = coll_upd_top_left(col1,  p1_1->x - speed, p1_1->y);
	p1_2 = coll_upd_bot_right(col1, p1_2->x - speed, p1_2->y);
	p2_1 = coll_upd_top_right(col1, p2_1->x - speed, p2_1->y);
	p2_2 = coll_upd_bot_left(col1,  p2_2->x - speed, p2_2->y);
	target_p1 = coll_upd_top_right(col2, *col2->x + col2->width, *col2->y);
	target_p2 = coll_upd_bot_right(col2, *col2->x + col2->width, *col2->y + col2->height);
	return (do_line_intersect_segment(*p1_1, *p1_2, *target_p1, *target_p2) &&
			do_line_intersect_segment(*p2_1, *p2_2, *target_p1, *target_p2));
}

int inter_up(t_collider *col1, t_collider *col2, int speed)
{
	t_point *p1_1;
	t_point *p1_2;
	t_point *p2_1;
	t_point *p2_2;
	t_point *target_p1;
	t_point *target_p2;

	p1_1 = coll_upd_top_left(col1, *col1->x, *col1->y);
	p1_2 = coll_upd_bot_right(col1, *col1->x + col1->width, *col1->y + col1->height);
	p2_1 = coll_upd_top_right(col1, *col1->x + col1->width, *col1->y);
	p2_2 = coll_upd_bot_left(col1, *col1->x, *col1->y + col1->height);
	p1_1 = coll_upd_top_left(col1,  p1_1->x, p1_1->y + speed);
	p1_2 = coll_upd_bot_right(col1, p1_2->x, p1_2->y + speed);
	p2_1 = coll_upd_top_right(col1, p2_1->x, p2_1->y + speed);
	p2_2 = coll_upd_bot_left(col1,  p2_2->x, p2_2->y + speed);
	target_p1 = coll_upd_top_left(col2, *col2->x, *col2->y);
	target_p2 = coll_upd_top_right(col2, *col2->x + col2->width, *col2->y);
	return (do_line_intersect_segment(*p1_1, *p1_2, *target_p1, *target_p2) &&
			do_line_intersect_segment(*p2_1, *p2_2, *target_p1, *target_p2));
}

int inter_down(t_collider *col1, t_collider *col2, int speed)
{
	t_point *p1_1;
	t_point *p1_2;
	t_point *p2_1;
	t_point *p2_2;
	t_point *target_p1;
	t_point *target_p2;

	p1_1 = coll_upd_top_left(col1, *col1->x, *col1->y);
	p1_2 = coll_upd_bot_right(col1, *col1->x + col1->width, *col1->y + col1->height);
	p2_1 = coll_upd_top_right(col1, *col1->x + col1->width, *col1->y);
	p2_2 = coll_upd_bot_left(col1, *col1->x, *col1->y + col1->height);
	p1_1 = coll_upd_top_left(col1,  p1_1->x, p1_1->y - speed);
	p1_2 = coll_upd_bot_right(col1, p1_2->x, p1_2->y - speed);
	p2_1 = coll_upd_top_right(col1, p2_1->x, p2_1->y - speed);
	p2_2 = coll_upd_bot_left(col1,  p2_2->x, p2_2->y - speed);
	target_p1 = coll_upd_bot_left(col2, *col2->x, *col2->y + col2->height);
	target_p2 = coll_upd_bot_right(col2, *col2->x + col2->width, *col2->y + col2->height);
	return (do_line_intersect_segment(*p1_1, *p1_2, *target_p1, *target_p2) &&
			do_line_intersect_segment(*p2_1, *p2_2, *target_p1, *target_p2));
}

int inter_here(t_collider *col1, t_collider *col2)
{
	t_point *p1_1;
	t_point *p1_2;
	t_point *p2_1;
	t_point *p2_2;
	t_point *target_p1;
	t_point *target_p2;

	p1_1 = coll_upd_top_left(col1, *col1->x, *col1->y);
	p1_2 = coll_upd_bot_right(col1, *col1->x + col1->width, *col1->y + col1->height);
	p2_1 = coll_upd_top_right(col1, *col1->x + col1->width, *col1->y);
	p2_2 = coll_upd_bot_left(col1, *col1->x, *col1->y + col1->height);
	p1_1 = coll_upd_top_left(col1, 	p1_1->x, p1_1->y);
	p1_2 = coll_upd_bot_right(col1, p1_2->x, p1_2->y);
	p2_1 = coll_upd_top_right(col1, p2_1->x, p2_1->y);
	p2_2 = coll_upd_bot_left(col1,  p2_2->x, p2_2->y);
	target_p1 = coll_upd_bot_left(col2, *col2->x, *col2->y + col2->height / 2);
	target_p2 = coll_upd_bot_right(col2, *col2->x + col2->width, *col2->y + col2->height / 2);
	return (do_line_intersect_segment(*p1_1, *p1_2, *target_p1, *target_p2) &&
			do_line_intersect_segment(*p2_1, *p2_2, *target_p1, *target_p2));
}