/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:53:23 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/03 21:05:10 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"
#include <stdio.h>

static void	init_collider_points(t_collider *collider)
{
	collider->points[0] = NULL;
	collider->points[1] = NULL;
	collider->points[2] = NULL;
	collider->points[3] = NULL;
	collider->points[4] = NULL;
}

int 	feel_collider(t_collider *collider)
{
	int	x;
	int	y;
	int	width;
	int	height;

	x = *collider->x + collider->align_top;
	y = *collider->y + collider->align_left;
	width = collider->width;
	height = collider->height;
	printf("create coll: %p\n", collider);
	collider->points = malloc(sizeof(t_point *) * 5);
	if (!collider->points)
		return (1);
	init_collider_points(collider);
	collider->points[0] = make_point(x, y);
	if (!collider->points[0])
		return (1);
	collider->points[1] = make_point(x + width, y);
	if (!collider->points[1])
		return (1);
	collider->points[2] = make_point(x + width, y + height);
	if (!collider->points[2])
		return (1);
	collider->points[3] = make_point(x, y + height);
	if (!collider->points[3])
		return (1);
	collider->points[4] = NULL;
	return (0);
}

t_collider	*make_collider(int height, int width, int *x, int *y)
{
	t_collider	*collider; 

	collider = malloc(sizeof(t_collider));
	if (!collider)
		return (NULL);
	collider->x = x;
	collider->y = y;
	collider->align_left = 0;	
	collider->align_top = 0;
	collider->width = width;
	collider->height = height;
	collider->points = NULL;
	if (feel_collider(collider) != 0)
		return (free_collider(collider), NULL);
	return (collider);
}

t_collider	*coll_set_align(t_collider *coll, int top, int left)
{
	int		counter;

	if (!coll)
		return (NULL);
	printf("coll set align : %p\n", coll);
	coll->align_top = top;
	coll->align_left = left;
	counter = 0;
	while (coll->points[counter])
	{
		free(coll->points[counter]);
		counter++;
	}
	free(coll->points);
	if (feel_collider(coll) != 0)
		return (free_collider(coll), NULL);
	return (coll);
}


void	free_collider(t_collider *coll)
{
	int counter;

	if (!coll)
		return ;
	counter = 0;
	while(coll->points && coll->points[counter])
	{	
		printf("\tcoll point %d : %d %d \n", counter, coll->points[counter]->x, coll->points[counter]->y);
		free(coll->points[counter]);
		counter++;
	}	
	if (coll->points)
		free(coll->points);
	free(coll);
}

t_point	*coll_upd_top_left(t_collider *collider, int x, int y)
{
	t_point *point;

	point = collider->points[0];
	update_point(point, x, y);
	return (point);
}

t_point *coll_get_top_left(t_collider *collider)
{
	return (collider->points[0]);
}

t_point	*coll_upd_top_right(t_collider *collider, int x, int y)
{
	if (collider->points[1]->x != x)
		collider->points[1]->x = x;
		
	if (collider->points[1]->y != y)
		collider->points[1]->y = y;

	return (collider->points[1]);
}

t_point *coll_get_top_right(t_collider *collider)
{
	return (collider->points[1]);
}

t_point	*coll_upd_bot_right(t_collider *collider, int x, int y)
{
	if (collider->points[2]->x != x)
		collider->points[2]->x = x;
		
	if (collider->points[2]->y != y)
		collider->points[2]->y = y;

	return (collider->points[2]);
}

t_point *coll_get_bot_right(t_collider *collider)
{
	return (collider->points[2]);
}

t_point	*coll_upd_bot_left(t_collider *collider, int x, int y)
{
	if (collider->points[3]->x != x)
		collider->points[3]->x = x;
		
	if (collider->points[3]->y != y)
		collider->points[3]->y = y;

	return (collider->points[3]);
}

t_point *coll_get_bot_left(t_collider *collider)
{
	return (collider->points[3]);
}