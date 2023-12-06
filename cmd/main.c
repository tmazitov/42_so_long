/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:08:01 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/06 15:08:37 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	check_paths(t_game *game)
{
	// TODO : make the additional validation for the paths:
	//	* path player -> exit is exists ? (save this way to show the road)
	//	* path player -> each one collecatable is exists ?
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	*map;

	if (argc != 2)
		return (1);
	map = make_map(argv[1]);
	if (!map)
		return (1);
	game = make_game((map->height + 1) * 64, map->width * 64, "so_long");
	if (!game)
	{
		free_map(map);
		return (1);
	}
	game->scene = make_scene(game->mlx, map, game->height, game->width);
	if (!game->scene)
	{
		free_game(game);
		return (1);
	}
	if (check_paths(game) != 0)
	{
		free_game(game);
		return (1);
	}
	game->player = make_player(game->mlx, 128, 128);
	if (!game->player)
	{
		free_game(game);
		return (1);
	}
	game->player->x = game->scene->player_x;
	game->player->y = game->scene->player_y;
	game->player->last_x = game->player->x;
	game->player->last_y = game->player->y;
	mlx_loop_hook(game->mlx, render_hook, game);
	mlx_key_hook(game->window, player_control_hook, game);
	mlx_loop(game->mlx);
}