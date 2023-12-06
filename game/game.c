/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:52:19 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/06 14:38:32 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	*free_game(t_game *game)
{
	if (!game)
		return (NULL);
	if (game->scene)
		free_scene(game->scene);
	if (game->player)
		free_player(game->player);
	if (game->window)
		mlx_destroy_window(game->window, game->mlx);
	if (game->mlx)
		free(game->mlx);
	free(game);
	return (NULL);
}

static void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->scene = NULL;
	game->player = NULL;
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
		return (free_game(game), NULL);
	game->window = mlx_new_window(game->mlx,  width, height, title);
	if (!game->window)
		return (free_game(game), NULL);
	game->height = height;
	game->width = width;
	return (game);
}