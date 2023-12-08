/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:08:01 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/08 15:50:08 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	check_collectable_paths(t_game *game)
{
	t_path		*path;
	t_a_point	*src;
	t_a_point	*dest;
	t_chest		*chest;
	int			counter;
	
	printf("src created\n");
	src = make_a_point(game->player->x, game->player->y, NULL);
	if (!src)
		return (1);
	counter = 0;
	while (game->scene->chests[counter])
	{
		ft_printf("# chest %d path\t-\t", counter);
		chest = game->scene->chests[counter++];
		dest = make_a_point(chest->x, chest->y, NULL);
		if (!dest)
			return (ft_printf("fail\n"), free_a_point(src), 1);
		path = calc_path(src, dest, game->scene->game_objs_points);
		free_a_point(dest);
		if (!path)
			return (ft_printf("fail\n"), free_a_point(src), 1);
		free_path(path);
		ft_printf("ok\n");
	}
	return (free_a_point(src), 0);
}

static int	check_exit_path(t_game *game)
{
	t_path		*path;
	t_a_point	*src;
	t_a_point	*dest;
	t_exit		*exit;
	
	src = make_a_point(game->player->x, game->player->y, NULL);
	if (!src)
		return (1);
	ft_printf("# exit path\t-\t");
	exit = game->scene->exit;
	dest = make_a_point(exit->x, exit->y, NULL);
	if (!dest)
		return (ft_printf("fail\n"), free_a_point(src), 1);
	path = calc_path(src, dest, game->scene->game_objs_points);
	free_a_point(dest);
	if (!path)
		return (ft_printf("fail\n"), free_a_point(src), 1);
	free_path(path);
	ft_printf("ok\n");
	return (free_a_point(src), 0);
}

static int	check_paths(t_game *game)
{
	// TODO : make the additional validation for the paths:
	// * path player -> exit is exists ? (save this way to show the road)
	// * path player -> each one collecatable is exists ? 
	if (check_collectable_paths(game) != 0)
		return (1);
	if (check_exit_path(game) != 0)
		return (1);
	return (0);
}

static int	window_exit(void *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
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
	if (check_paths(game) != 0)
	{
		free_game(game);
		return (1);
	}

	mlx_hook(game->window, 17, 0, window_exit, game);
	mlx_key_hook(game->window, player_control_hook, game);
	mlx_loop_hook(game->mlx, render_hook, game);
	mlx_loop(game->mlx);  
}