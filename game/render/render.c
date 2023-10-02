/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:51:46 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/02 17:52:25 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int render_player(t_game *game)
{
	int		x;
	int		y;
	t_anime_tile	*tile;
	t_anime			*anime;

	if (game->player->current_task)
		anime = task_proccess(game->player);
	else
		anime = game->player->anime->idle;
	tile = get_next_tile(anime);
	x = game->player->x;
	y = game->player->y;
	mlx_put_image_to_window(game->mlx, game->window, tile->image, x, y);
	return (0);
}

int	render_scene(t_game *game)
{
	int		x;
	int		y;
	void	*image;

	x = 0;
	image = game->scene->textures->grass;
	while (x < game->scene->width)
	{
		y = 0;
		while (y < game->scene->height)
		{
			mlx_put_image_to_window(game->mlx, game->window, image, x, y);
			y += 128;
		}
		x += 128;	
	}
	return (0);
}

int	render_hook(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	render_scene(game);
	render_player(game);
	return (0);
}
