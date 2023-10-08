/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:53:23 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/08 18:53:20 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"

int 	feel_collider(t_collider *collider)
{
	int	x;
	int	y;
	int	width;
	int	height;

	x = *collider->x;
	y = *collider->y;
	width = collider->width;
	height = collider->height;
	collider->points = malloc(sizeof(t_point *) * 5);
	if (!collider->points)
		return (0);
	collider->points[0] = make_point(x, y);
	if (!collider->points[0])
		return (0);
	collider->points[1] = make_point(x + width, y);
	if (!collider->points[1])
		return (0);
	collider->points[2] = make_point(x + width, y + height);
	if (!collider->points[2])
		return (0);
	collider->points[3] = make_point(x, y + height);
	if (!collider->points[3])
		return (0);
	collider->points[4] = NULL;
	return (1);
}

t_collider	*make_collider(int height, int width, int *x, int *y)
{
	t_collider	*collider; 

	collider = malloc(sizeof(t_collider));
	if (!collider)
		return (NULL);
	collider->x = x;	
	collider->y = y;	
	collider->width = width;
	collider->height = height;
	if (!feel_collider(collider))
		return (free_collider(collider), NULL);
	return (collider);	
}



void	free_collider(t_collider *collider)
{
	int counter;

	if (collider->points)
	{	
		counter = 0;
		while(collider->points[counter])
			free_point(collider->points[counter]);
		free(collider->points);
	}
	free(collider);
}

t_point	*coll_upd_top_left(t_collider *collider, int x, int y)
{
	if (collider->points[0]->x != x)
		collider->points[0]->x = x;
		
	if (collider->points[0]->y != y)
		collider->points[0]->y = y;

	return (collider->points[0]);
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