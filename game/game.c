/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:52:19 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 18:43:56 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h>

static void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->scene = NULL;
	game->player = NULL;
	game->writer = NULL;
}

void	*free_game(t_game *game)
{
	if (!game)
		return (NULL);
	game->blocker = 1;
	if (game->scene)
		free_scene(game->scene);
	if (game->player)
		free_player(game->player);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		free(game->mlx);
	free(game);
	return (NULL);
}

t_game	*make_game(int height, int width, char *title)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	init_game(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_game(game));
	game->window = mlx_new_window(game->mlx, width, height, title);
	if (!game->window)
		return (free_game(game));
	game->writer = make_writer(game->mlx, game->window, 10);
	if (!game->writer)
		return (free_game(game));
	if (feed_game_writer(game->writer) != 0)
		return (free_game(game));
	game->height = height;
	game->width = width;
	game->blocker = 0;
	return (game);
}
