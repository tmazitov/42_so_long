/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:13:16 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 22:30:24 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"

double	cross_product(t_point *a, t_point *b)
{
	return (a->x * b->y - a->y * b->x);
}

static int	free_support_points(t_point *v1, t_point *v2, t_point *v3)
{
	free_point(v1);
	free_point(v2);
	free_point(v3);
	return (0);
}

int	inter_segm(t_point *p1, t_point *p2, t_point *q1, t_point *q2)
{
	t_point	*v1;
	t_point	*v2;
	t_point	*v3;
	double	t1;
	double	t2;

	v1 = make_point(p2->x - p1->x, p2->y - p1->y);
	v2 = make_point(q2->x - q1->x, q2->y - q1->y);
	v3 = make_point(q1->x - p1->x, q1->y - p1->y);
	if (!v1 || !v2 || !v3)
		return (0);
	if (cross_product(v1, v3) == 0 || cross_product(v1, v2) == 0)
		return (free_support_points(v1, v2, v3));
	t1 = cross_product(v3, v2) / cross_product(v1, v2);
	t2 = cross_product(v3, v1) / cross_product(v1, v2);
	free_support_points(v1, v2, v3);
	return (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1);
}

int	check_intersection(t_collider *col1, t_collider *col2, int target,
		int speed)
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
