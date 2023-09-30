/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:08:01 by tmazitov          #+#    #+#             */
/*   Updated: 2023/09/30 18:36:36 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// int	key_hook(int keycode, t_game *game)
// {
// 	printf("Hello from key_hook! Keycode : %d,Vars : %p \n", keycode, game);
// 	return (0);
// }

int	main(void)
{
	t_game	*game;

	game = make_game(512, 512, "so_long");
	if (!game)
		return (1);
	game->player = make_player(game->mlx, 128, 128);
	mlx_loop_hook(game->mlx, render_hook, game);
	// mlx_key_hook(game->window, key_hook, game);
	mlx_loop(game->mlx);
}