/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:19:38 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/11 00:09:15 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "../../utils/mlx_provider/mlx_provider.h"
# include <stdlib.h>

typedef struct s_image
{
	void	*content;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		height;
	int		width;
	void	*mlx;
}			t_image;

t_image		*make_image(void *mlx, int height, int width);
t_image		*make_image_v2(void *mlx, char *path);
void		*free_image(t_image *image);

#endif // !IMAGE_H