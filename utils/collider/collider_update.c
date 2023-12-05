/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:44:37 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/05 18:46:13 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"

t_point	*coll_upd_top_left(t_collider *collider, int x, int y)
{
	t_point *point;

	point = collider->top_l;
	update_point(point, x, y);
	return (point);
}

t_point	*coll_upd_top_right(t_collider *collider, int x, int y)
{
	t_point *point;

	point = collider->top_r;
	update_point(point, x, y);
	return (point);
}

t_point	*coll_upd_bot_right(t_collider *collider, int x, int y)
{
	t_point *point;

	point = collider->bot_r;
	update_point(point, x, y);
	return (point);
}

t_point	*coll_upd_bot_left(t_collider *collider, int x, int y)
{
	t_point *point;

	point = collider->bot_l;
	update_point(point, x, y);
	return (point);
}

void 	update_collider(t_collider *coll)
{
	int	x;
	int	y;
	int	width;
	int	height;

	x = *(coll->x) + coll->align_top;
	y = *(coll->y) + coll->align_left;
	width = coll->width;
	height = coll->height;
	coll_upd_top_left(coll, x, y);
	coll_upd_top_right(coll, x + width, y);
	coll_upd_bot_right(coll, x + width, y + height);
	coll_upd_bot_left(coll, x, y + height);
}