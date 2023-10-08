/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:13:16 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/08 19:26:55 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"

int	check_line_intersection(int line1x, int line1y, int line2x, int line2y)
{
	double	len_1;
	double	len_2;
	double epsilon;

	if ( !line1x && !line2x && !line1y && !line2y)
		return (-1);
	len_1 = sqrt(line1x * line1x + line1y * line1y);
	len_2 = sqrt(line2x * line2x + line2y * line2y);
	epsilon = 0.000001;
	
	return !(fabs(line1x/len_1 - line2x/len_2) < epsilon && 
			fabs(line1y/len_1 - line2y/len_2) < epsilon);
}


double crossProduct(t_point a, t_point b) {
    return a.x * b.y - a.y * b.x;
}

// Function to check if two line segments intersect.
int doLineSegmentsIntersect(t_point p1, t_point p2, t_point q1, t_point q2) {
    t_point v1 = {p2.x - p1.x, p2.y - p1.y};
    t_point v2 = {q2.x - q1.x, q2.y - q1.y};
    t_point v3 = {q1.x - p1.x, q1.y - p1.y};

    double cross1 = crossProduct(v1, v3);
    double cross2 = crossProduct(v1, v2);

    if (cross1 == 0 && cross2 == 0) {
        // The line segments are collinear (may or may not be intersecting).
        // You can add additional logic here to handle this case.
        return 0;
    }

    // Check if the line segments intersect.
    if (cross1 == 0 || cross2 == 0) {
        return 0;
    }

    double t1 = crossProduct(v3, v2) / cross2;
    double t2 = crossProduct(v3, v1) / cross2;

    if (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1) {
        // The line segments intersect.
        return 1;
    }

    // The line segments do not intersect.
    return 0;
}


int	check_intersection(t_collider *col1, t_collider *col2, int target, int speed)
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

	if (target == INTER_STRAIGHT)
	{
		p1_1 = coll_upd_top_left(col1,  p1_1->x + speed, p1_1->y);
		p1_2 = coll_upd_bot_right(col1, p1_2->x + speed, p1_2->y);
		p2_1 = coll_upd_top_right(col1, p2_1->x + speed, p2_1->y);
		p2_2 = coll_upd_bot_left(col1,  p2_2->x + speed, p2_2->y);
		target_p1 = coll_upd_top_left(col2, *col2->x, *col2->y);
		target_p2 = coll_upd_bot_left(col2, *col2->x, *col2->y + col2->height);
		return (doLineSegmentsIntersect(*p1_1, *p1_2, *target_p1, *target_p2) &&
				doLineSegmentsIntersect(*p2_1, *p2_2, *target_p1, *target_p2));
	}
	if (target == INTER_BACK)
	{
		p1_1 = coll_upd_top_left(col1,  p1_1->x - speed, p1_1->y);
		p1_2 = coll_upd_bot_right(col1, p1_2->x - speed, p1_2->y);
		p2_1 = coll_upd_top_right(col1, p2_1->x - speed, p2_1->y);
		p2_2 = coll_upd_bot_left(col1,  p2_2->x - speed, p2_2->y);
		target_p1 = coll_upd_top_right(col2, *col2->x + col2->width, *col2->y);
		target_p2 = coll_upd_bot_right(col2, *col2->x + col2->width, *col2->y + col2->height);
		return (doLineSegmentsIntersect(*p1_1, *p1_2, *target_p1, *target_p2) &&
				doLineSegmentsIntersect(*p2_1, *p2_2, *target_p1, *target_p2));
	}
	if (target == INTER_UP)
	{
		p1_1 = coll_upd_top_left(col1,  p1_1->x, p1_1->y + speed);
		p1_2 = coll_upd_bot_right(col1, p1_2->x, p1_2->y + speed);
		p2_1 = coll_upd_top_right(col1, p2_1->x, p2_1->y + speed);
		p2_2 = coll_upd_bot_left(col1,  p2_2->x, p2_2->y + speed);
		target_p1 = coll_upd_top_left(col2, *col2->x, *col2->y);
		target_p2 = coll_upd_top_right(col2, *col2->x + col2->width, *col2->y);
		return (doLineSegmentsIntersect(*p1_1, *p1_2, *target_p1, *target_p2) &&
				doLineSegmentsIntersect(*p2_1, *p2_2, *target_p1, *target_p2));
	}
	if (target == INTER_DOWN)
	{
		p1_1 = coll_upd_top_left(col1,  p1_1->x, p1_1->y - speed);
		p1_2 = coll_upd_bot_right(col1, p1_2->x, p1_2->y - speed);
		p2_1 = coll_upd_top_right(col1, p2_1->x, p2_1->y - speed);
		p2_2 = coll_upd_bot_left(col1,  p2_2->x, p2_2->y - speed);
		target_p1 = coll_upd_bot_left(col2, *col2->x, *col2->y + col2->height);
		target_p2 = coll_upd_bot_right(col2, *col2->x + col2->width, *col2->y + col2->height);
		return (doLineSegmentsIntersect(*p1_1, *p1_2, *target_p1, *target_p2) &&
				doLineSegmentsIntersect(*p2_1, *p2_2, *target_p1, *target_p2));
	}
	// if (target == INTER_UP)
	// {
	// 	p1_1 = coll_upd_top_left(col1,  p1_1->x, p1_1->y + speed);
	// 	p1_2 = coll_upd_bot_right(col1, p1_2->x, p1_2->y + speed);
	// 	p2_1 = coll_upd_top_right(col1, p2_1->x, p2_1->y + speed);
	// 	p2_2 = coll_upd_bot_left(col1,  p2_2->x, p2_2->y + speed);
	// 	target_p1 = coll_upd_top_right(col2, *col2->x + col2->width, *col2->y);
	// 	target_p2 = coll_upd_bot_right(col2, *col2->x + col2->width, *col2->y + col2->height);
	// 	return (doLineSegmentsIntersect(*p1_1, *p1_2, *target_p1, *target_p2) &&
	// 			doLineSegmentsIntersect(*p2_1, *p2_2, *target_p1, *target_p2));
	// }
	// if (target == INTER_DOWN)
	// {
	// 	target_p1 = coll_upd_top_left(col1, *col1->x + speed, *col1->y + col1->height);
	// 	target_p2 = coll_upd_top_left(col1, *col1->x + col1->width + speed, *col1->y);
	// 	return (doLineSegmentsIntersect(*p1_1, *p1_2, *target_p1, *target_p2) &&
	// 			doLineSegmentsIntersect(*p2_1, *p2_2, *target_p1, *target_p2));
	// }

	return (0);
}


