/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_feel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:31:07 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/11 03:40:01 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	feel_enemies(void *mlx, t_map *map, t_scene *scene)
{
	int	counter;
	int	x;
	int	y;

	y = 0;
	counter = 0;
	while (map->content[y])
	{
		x = 0;
		while (map->content[y][x])
		{
			if (map->content[y][x] == 'S')
			{
				scene->enemies[counter] = make_enemy(mlx, x, y);
				if (!scene->enemies[counter++])
					return (3);
			}
			x++;
		}
		y++;
	}
	scene->enemies[counter] = NULL;
	return (0);
}

int	feel_trees(t_map *map, t_scene *scene)
{
	int	counter;
	int	x;
	int	y;
	int	is_border;

	y = 0;
	counter = 0;
	while (map->content[y])
	{
		x = 0;
		while (map->content[y][x])
		{
			if (map->content[y][x] == '1')
			{
				is_border = !y || !x || !map->content[y][x + 1];
				scene->objs[counter] = make_tree(scene, is_border, x, y);
				if (!scene->objs[counter++])
					return (1);
			}
			x++;
		}
		y++;
	}
	scene->objs[counter] = NULL;
	return (0);
}

int	feel_chests(void *mlx, t_map *map, t_scene *scene)
{
	int	counter;
	int	x;
	int	y;

	y = 0;
	counter = 0;
	while (map->content[y])
	{
		x = 0;
		while (map->content[y][x])
		{
			if (map->content[y][x] == 'C')
			{
				scene->chests[counter] = make_chest(mlx, 2, x, y);
				if (!scene->chests[counter++])
					return (1);
			}
			x++;
		}
		y++;
	}
	scene->chests[counter] = NULL;
	return (0);
}

int	feel_player_pos(t_map *map, t_scene *scene)
{
	int	counter;
	int	x;
	int	y;

	y = 0;
	counter = 0;
	while (map->content[y])
	{
		x = 0;
		while (map->content[y][x])
		{
			if (map->content[y][x] == 'P')
			{
				scene->player_x = x * 64;
				scene->player_y = (y + 1) * 64;
				counter++;
			}
			x++;
		}
		y++;
	}
	return (counter != 1);
}

int	feel_player_exit(t_map *map, t_scene *scene)
{
	int	counter;
	int	x;
	int	y;

	y = 0;
	counter = 0;
	while (map->content[y])
	{
		x = 0;
		while (map->content[y][x])
		{
			if (map->content[y][x] == 'E')
			{
				scene->exit_x = x * 64;
				scene->exit_y = (y + 1) * 64;
				counter++;
			}
			x++;
		}
		y++;
	}
	return (counter != 1);
}
