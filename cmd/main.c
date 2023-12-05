/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:08:01 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/05 14:52:28 by tmazitov         ###   ########.fr       */
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

	screen_height = 1080;
	screen_width = 1920;

	game = make_game(screen_height, screen_width, "so_long");
	if (!game)
		return (1);
	game->scene = make_scene(game->mlx, "maps/map1.ber", screen_height, screen_width);
	if (!game->scene)
	{
		printf("wrong scene\n");
		return (1);
	}
	game->player = make_player(game->mlx, 128, 128);
	if (!game->player)
	{
		printf("wrong player\n");
		return (1);
	}
	printf("player: %d %d\n", game->scene->player_x, game->scene->player_y);
	game->player->x = game->scene->player_x;
	game->player->y = game->scene->player_y;
	game->player->last_x = game->player->x;
	game->player->last_y = game->player->y;
	mlx_loop_hook(game->mlx, render_hook, game);
	mlx_key_hook(game->window, player_control_hook, game);
	mlx_loop(game->mlx);
}