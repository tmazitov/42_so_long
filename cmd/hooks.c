/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:46:43 by tmazitov          #+#    #+#             */
/*   Updated: 2024/03/13 17:05:46 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	exit_game(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_key_hook(game->window, player_control_hook, game);
	mlx_loop_hook(game->mlx, render_hook, game);
	mlx_hook(game->window, 17, 1L << 17, exit_game, game);
	mlx_loop(game->mlx);
}
