/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:53:23 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/05 18:46:19 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"
#include <stdio.h>

static void	init_collider_points(t_collider *collider)
{
	collider->top_l = NULL;
	collider->top_r = NULL;
	collider->bot_l = NULL;
	collider->bot_r = NULL;
}

int 	feel_collider(t_collider *collider)
{
	int	x;
	int	y;
	int	width;
	int	height;

	x = *(collider->x) + collider->align_top;
	y = *(collider->y) + collider->align_left;
	width = collider->width;
	height = collider->height;
	init_collider_points(collider);
	collider->top_r = make_point(x, y);
	if (!collider->top_r)
		return (1);
	collider->top_l = make_point(x + width, y);
	if (!collider->top_l)
		return (1);
	collider->bot_r = make_point(x + width, y + height);
	if (!collider->bot_r)
		return (1);
	collider->bot_l = make_point(x, y + height);
	if (!collider->bot_l)
		return (1);
	return (0);
}

t_collider	*make_collider(int height, int width, int *x, int *y)
{
	t_collider	*coll; 

	coll = malloc(sizeof(t_collider));
	if (!coll)
		return (NULL);
	coll->x = x;
	coll->y = y;
	coll->align_left = 0;	
	coll->align_top = 0;
	coll->width = width;
	coll->height = height;
	if (feel_collider(coll) != 0)
		return (free_collider(coll), NULL);
	return (coll);
}

t_collider	*coll_set_align(t_collider *coll, int top, int left)
{

	if (!coll)
		return (NULL);
	coll->align_top = top;
	coll->align_left = left;
	update_collider(coll);
	return (coll);
}


void	free_collider(t_collider *coll)
{
	if (!coll)
		return ;
	if (coll->top_l)
		free_point(coll->top_l);
	if (coll->top_r)
		free_point(coll->top_r);
	if (coll->bot_l)
		free_point(coll->bot_l);
	if (coll->bot_r)
		free_point(coll->bot_r);
	free(coll);
}
