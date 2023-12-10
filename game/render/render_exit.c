/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 02:35:18 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/11 03:01:48 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_exit(t_game *game)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	t_image	*image;

	mlx = game->mlx;
	win = game->window;
	image = game->scene->exit->image;
	x = game->scene->exit_x + image->width / 2;
	y = game->scene->exit_y;
	mlx_put_image_to_window(mlx, win, image->content, x, y);
}
