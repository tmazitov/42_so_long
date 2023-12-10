/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:46:43 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 22:48:01 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	window_exit(void *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->window, 17, 0, window_exit, game);
	mlx_key_hook(game->window, player_control_hook, game);
	mlx_loop_hook(game->mlx, render_hook, game);
	mlx_loop(game->mlx);
}
