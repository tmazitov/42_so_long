/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colider_shift.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:21:03 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 22:35:24 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"

void	shift_point(t_point *point, int x, int y)
{
	update_point(point, point->x + x, point->y + y);
}

void	sync_collider(t_collider *coll)
{
	coll_upd_top_left(coll, *coll->x, *coll->y);
	coll_upd_bot_right(coll, *coll->x + coll->width, *coll->y + coll->height);
	coll_upd_top_right(coll, *coll->x + coll->width, *coll->y);
	coll_upd_bot_left(coll, *coll->x, *coll->y + coll->height);
}

void	shift_collider(t_collider *coll, int x, int y)
{
	shift_point(coll->top_l, x, y);
	shift_point(coll->top_r, x, y);
	shift_point(coll->bot_l, x, y);
	shift_point(coll->bot_r, x, y);
}
