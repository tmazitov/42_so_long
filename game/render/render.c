/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:51:46 by tmazitov          #+#    #+#             */
/*   Updated: 2023/09/30 18:54:07 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int render_player(t_game *game)
{
	int		x;
	int		y;
	t_anime_tile	*tile;
	t_player_anime	*anime;

	anime = game->player->anime;
	tile = get_next_tile(anime->idle);
	x = game->player->x;
	y = game->player->y;
	mlx_put_image_to_window(game->mlx, game->window, tile->image, x, y);
	return (0);
}

int	render_hook(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	render_player(game);
	return (0);
}
