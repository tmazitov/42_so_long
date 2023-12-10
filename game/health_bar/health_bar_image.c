/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_bar_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:12:46 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:04:50 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "health_bar.h"
#include <math.h>
#include <stdio.h>

static void	make_top_border(int *buffer, int width, int line_bytes)
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

static void	make_bot_border(int *buffer, int height, int width, int line_bytes)
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

static void	make_main(t_image *i, int *buffer, int count, int max)
{
	int	x;
	int	y;
	int	percent;

	y = 2;
	percent = round((count / (float)max) * 60);
	while (y < i->height - 2)
	{
		x = 0;
		while (x < i->width)
		{
			if (x < 2 || x >= i->width - 2)
				buffer[(y * i->line_bytes) + x] = HEALTH_BAR_BORDER_C;
			else if (x <= percent)
				buffer[(y * i->line_bytes) + x] = HEALTH_BAR_HEALTH_C;
			x++;
		}
		y++;
	}
}

t_image	*make_health_bar_image(void *mlx, t_health_bar *bar, int count)
{
	int		*buffer;
	t_image	*i;
	int		*lb;
	int		*e;

	if (!bar)
		return (NULL);
	i = make_image(mlx, 10, 64);
	if (!i)
		return (NULL);
	lb = &i->line_bytes;
	e = &i->endian;
	buffer = (int *)mlx_get_data_addr(i->content, &i->pixel_bits, lb, e);
	if (!buffer)
		return (free_image(i));
	i->line_bytes /= 4;
	make_bot_border(buffer, i->height, i->width, bar->max);
	make_top_border(buffer, i->width, i->line_bytes);
	make_main(i, buffer, count, bar->max);
	return (i);
}
