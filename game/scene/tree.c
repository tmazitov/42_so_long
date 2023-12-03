/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:20:36 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/03 18:45:19 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"


static void	objs_counting(char **map, int *ch, int *o, int *en)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == 'C')
				*ch = *ch + 1;
			if (map[y][x] == 'E')
				*en = *en + 1;
			if (map[y][x] == '1')
				*o = *o + 1;
			x++;
		}
		y++;
	}
}

static int	init_feel_scene(char **map, t_scene *scene)
{
	int chests;
	int enemies;
	int objs;

	enemies = 0;
	chests = 0;
	objs = 0;
	objs_counting(map, &chests, &objs, &enemies);
	scene->objs = malloc(sizeof(t_scene_obj *) * ((objs + 1)));
	if (!scene->objs)
		return (1);
	scene->chests = malloc(sizeof(t_chest *) * ((chests + 1)));
	if (!scene->chests)
		return (1);
	scene->enemies = malloc(sizeof(t_enemy *) * ((enemies + 1)));
	if (!scene->enemies)
		return (1);
	return (0);
}

int	feel_scene(void *mlx, char **map, t_scene *scene)
{
	if (init_feel_scene(map, scene) != 0)
		return (1);
	if (feel_enemies(mlx, map, scene) != 0)
		return (1);
	if (feel_trees(map, scene) != 0)
		return (1);
	if (feel_chests(mlx, map, scene) != 0)
		return (1);
	if (feel_player_pos(map, scene) != 0)
		return (1);
	return (0);
}