/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:52:19 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/29 12:06:48 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	*free_game(t_game *game)
{
	if (game->mlx)
		free(game->mlx);
	if (game->window)
		free(game->window);
	if (game)
		free(game);
	return (NULL);
}

t_game	*make_game(int height, int width, char *title)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_game(game), NULL);
	game->window = mlx_new_window(game->mlx,  width, height, title);
	if (!game->window)
		return (free_game(game), NULL);
	game->player = NULL;
	return (game);
}