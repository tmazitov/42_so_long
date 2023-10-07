/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:53:23 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/07 18:08:31 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"

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
	return (collider);	
}

void	free_collider(t_collider *collider)
{
	free(collider);
}