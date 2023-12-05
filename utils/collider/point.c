/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:48:54 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/05 14:50:37 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"
#include "stdio.h"

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

void	update_point(t_point *point, int x, int y)
{
	if (!point)
		return ;
	point->x = x;
	point->y = y;
}

void	free_point(t_point *point)
{
	if (!point)
		return ;
	free(point);
}
