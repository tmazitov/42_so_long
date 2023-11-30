/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_bar_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:12:46 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/30 17:18:35 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "health_bar.h"
#include <stdio.h>

static void		make_top_border(int *buffer, int width, int line_bytes)
{
	int	x;
	int	y;

	y = 0;
	while (y < 2)
	{
		x = 0;
		while (x < width)
			buffer[(y * line_bytes) + x++] = HEALTH_BAR_BORDER_C;
		y++;
	}
	buffer[(0 * line_bytes) + 0] = 0xFF000000;
	buffer[(0 * line_bytes) + 1] = 0xFF000000;
	buffer[(1 * line_bytes) + 0] = 0xFF000000;
	buffer[(0 * line_bytes) + width - 1] = 0xFF000000;
	buffer[(0 * line_bytes) + width - 2] = 0xFF000000;
	buffer[(1 * line_bytes) + width - 1] = 0xFF000000;
}
static void		make_bot_border(int *buffer, int height, int width, int line_bytes)
{
	int	x;
	int	y;

	y = height - 2;
	while (y < height)
	{
		x = 0;
		while (x < width)
			buffer[(y * line_bytes) + x++] = HEALTH_BAR_BORDER_C;
		y++;
	}
	buffer[((height - 1) * line_bytes) + 0] = 0xFF000000;
	buffer[((height - 1) * line_bytes) + 1] = 0xFF000000;
	buffer[((height - 2) * line_bytes) + 0] = 0xFF000000;
	buffer[((height - 1) * line_bytes) + width - 1] = 0xFF000000;
	buffer[((height - 1) * line_bytes) + width - 2] = 0xFF000000;
	buffer[((height - 2) * line_bytes) + width - 1] = 0xFF000000;
}

void	feel_health_bar_image(t_health_bar *bar)
{
	int		x;
	int		y;
	int		*buffer;
	t_image	*i;

	if (!bar || !bar->image)
		return ;
	i = bar->image;
	buffer = (int *)mlx_get_data_addr(i->content, &i->pixel_bits, &i->line_bytes, &i->endian);
	if (!buffer)
		return ;
	i->line_bytes /= 4;
	make_bot_border(buffer, i->height, i->width, i->line_bytes);
	make_top_border(buffer, i->width, i->line_bytes);
	y = 2;
	while (y < bar->image->height - 2)
	{
		x = 0;
		while (x < bar->image->width)
		{
			if (x < 2 || x >= bar->image->width - 2)
				buffer[(y * i->line_bytes) + x] = HEALTH_BAR_BORDER_C;
			else
				buffer[(y * i->line_bytes) + x] = HEALTH_BAR_HEALTH_C;
			x++;		
		}
		printf("\n");
		y++;
	}	
}