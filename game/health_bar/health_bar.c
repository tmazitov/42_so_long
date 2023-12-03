/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:53:01 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/02 15:26:44 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "health_bar.h"

static int	create_health_bar_images(void *mlx, t_health_bar *bar)
{
	int	counter;

	counter = 0;
	bar->images = malloc(sizeof(t_image *) * (bar->max + 2));
	if (!bar->images)
		return (1);
	while(counter <= bar->max)
	{
		bar->images[counter] = make_health_bar_image(mlx, bar, counter);
		if (!bar->images[counter])
			return (1);
		counter++;
	}
	bar->images[counter] = NULL;
	return (0);
}	

t_health_bar	*make_health_bar(void *mlx, int max)
{
	t_health_bar	*bar;

	bar = malloc(sizeof(t_health_bar));
	if (!bar)
		return (NULL);
	bar->max = max;
	bar->current = max;
	bar->images = NULL;
	if (create_health_bar_images(mlx, bar) != 0)
		return (free_health_bar(bar));
	return (bar);
}

t_image	*hb_get_image(t_health_bar *bar)
{
	if (bar->current == 0)
		return (NULL);
	return (bar->images[bar->current]);
}

void	*free_health_bar(t_health_bar *bar)
{
	int	counter;
	if (!bar)
		return (NULL);
	if (bar->images)
	{
		counter = 0;
		while (bar->images[counter])
			free_image(bar->images[counter++]);
		free(bar->images);
	}
	free(bar);
	return (NULL);
}