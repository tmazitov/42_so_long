/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:13:16 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/07 23:08:37 by tmazitov         ###   ########.fr       */
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
	t_point *line1x;
	t_point *line1y;
	t_point *line2x;
	t_point *line2y;
	t_point *line3x;
	t_point *line3y;

	if (target == INTER_STRAIGHT)
	{
		line1x = make_point(*col1->x + speed, *col1->y);
		line1y = make_point(*col1->x + col1->width + speed, *col1->y + col2->height);
		line2x = make_point(*col2->x, *col2->y);
		line2y = make_point(*col2->x, *col2->y + col2->height);
		line3x = make_point(*col1->x + speed, *col1->y + col1->height);
		line3y = make_point(*col1->x + col1->width + speed, *col1->y);
		return (doLineSegmentsIntersect(*line1x, *line1y, *line2x, *line2y) &&
				doLineSegmentsIntersect(*line3x, *line3y, *line2x, *line2y));
	}
	return (0);
}


