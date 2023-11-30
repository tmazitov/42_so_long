/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:13:16 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/30 12:52:27 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"

double cross_product(t_point *a, t_point *b) 
{
    return a->x * b->y - a->y * b->x;
}

int do_line_intersect_segment(t_point p1, t_point p2, t_point q1, t_point q2) 
{
    t_point *v1;
    t_point *v2;
    t_point *v3;
	double cross1;
	double cross2;
	double t1; 
	double t2;

	v1 = make_point(p2.x - p1.x, p2.y - p1.y);
	v2 = make_point(q2.x - q1.x, q2.y - q1.y);
	v3 = make_point(q1.x - p1.x, q1.y - p1.y);
	if (!v1 || !v2 || !v3)
		return (0);
    cross1 = cross_product(v1, v3);
    cross2 = cross_product(v1, v2);
    if (cross1 == 0 && cross2 == 0) 
        return 0;
    if (cross1 == 0 || cross2 == 0)
        return 0;
    t1 = cross_product(v3, v2) / cross2;
    t2 = cross_product(v3, v1) / cross2;
    return (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1);
}


int	check_intersection(t_collider *col1, t_collider *col2, int target, int speed)
{
	if (target == INTER_STRAIGHT)
		return (inter_straight(col1, col2, speed));
	else if (target == INTER_BACK)
		return (inter_back(col1, col2, speed));
	else if (target == INTER_UP)
		return (inter_up(col1, col2, speed));
	else if (target == INTER_DOWN)
		return (inter_down(col1, col2, speed));
	else 
		return (inter_here(col1, col2));
	return (0);
}


