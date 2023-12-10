/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:19:31 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:57:05 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

t_image	*make_image(void *mlx, int height, int width)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->endian = 0;
	image->line_bytes = 0;
	image->pixel_bits = 0;
	image->mlx = mlx;
	image->width = width;
	image->height = height;
	image->content = mlx_new_image(mlx, width, height);
	if (!image->content)
		return (free_image(image));
	return (image);
}

t_image	*make_image_v2(void *mlx, char *path)
{
	t_image	*image;
	int		*width;
	int		*height;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->endian = 0;
	image->line_bytes = 0;
	image->pixel_bits = 0;
	image->mlx = mlx;
	image->width = 0;
	image->height = 0;
	width = &image->width;
	height = &image->height;
	image->content = mlx_xpm_file_to_image(mlx, path, width, height);
	if (!image->content)
		return (free_image(image));
	return (image);
}

void	*free_image(t_image *image)
{
	if (!image)
		return (NULL);
	if (image->content)
		mlx_destroy_image(image->mlx, image->content);
	free(image);
	return (NULL);
}
