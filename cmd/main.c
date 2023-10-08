/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:08:01 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/08 19:23:01 by tmazitov         ###   ########.fr       */
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
	int		screen_height;
	int		screen_width;

	screen_height = 768;
	screen_width = 1024;

	game = make_game(screen_height, screen_width, "so_long");
	if (!game)
		return (1);
	game->player = make_player(game->mlx, 128, 128);
	if (!game->player)
	{
		printf("wrong player\n");
		return (1);
	}
	game->scene = make_scene(game->mlx, screen_height, screen_width);
	if (!game->scene)
	{
		printf("wrong scene\n");
		return (1);
	}
	mlx_loop_hook(game->mlx, render_hook, game);
	mlx_key_hook(game->window, player_control_hook, game->player);
	mlx_loop(game->mlx);
}