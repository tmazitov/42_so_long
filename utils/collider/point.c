/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:48:54 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/07 22:50:18 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"

t_point	*make_point(int x, int y)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}