/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:53:01 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/30 16:09:48 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "health_bar.h"

t_health_bar	*make_health_bar(void *mlx, int max)
{
	t_health_bar	*bar;

	bar = malloc(sizeof(t_health_bar));
	if (!bar)
		return (NULL);
	bar->max = max;
	bar->current = max;
	bar->image = make_image(mlx, 10, 64);
	if (!bar->image)
		return (free_health_bar(bar));
	feel_health_bar_image(bar);
	return (bar);
}

void	*free_health_bar(t_health_bar *bar)
{
	if (!bar)
		return (NULL);
	if (bar->image)
		free_image(bar->image);
	free(bar);
	return (NULL);
}