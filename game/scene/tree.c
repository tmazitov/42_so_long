/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:20:36 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/25 21:38:12 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"



int feel_tree(void *mlx, char **map, t_scene *scene)
{
	void	*tree_image;
	void	*stone_image;
	int		height_stone;
	int		width_stone;
	int		height;
	int		width;
	int		counter;
	int		chest_counter;
	int		enemy_counter;
	int		x;
	int		y;

	height = 128;
	width = 96;
	height_stone = 96;
	width_stone = 96;
	
	scene->objs = malloc(sizeof(t_scene_obj *) * (
		count_of_char(map, '1') +
		count_of_char(map, 'C') + 1));
	if (!scene->objs)
		return (1);
	scene->chests = malloc(sizeof(t_chest *) * ((count_of_char(map, 'C') + 1)));
	if (!scene->chests)
		return (1);
	scene->enemies = malloc(sizeof(t_enemy *) * ((count_of_char(map, 'S') + 1)));
	if (!scene->enemies)
		return (1);
	tree_image = mlx_xpm_file_to_image(mlx, "textures/tree/tree_4.xpm", &width, &height);
	if (!tree_image)
		return (2);
	stone_image = mlx_xpm_file_to_image(mlx, "textures/tree/tree_2.xpm", &width_stone, &height_stone);
	if (!stone_image)
		return (2);
	y = 0;
	counter = 0;
	chest_counter = 0;
	enemy_counter = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1' && (y == 0 || x == 0 || !map[y][x + 1]))
			{
				scene->objs[counter] = make_scene_obj(OBJ_TREE, tree_image, 64*x, 64*y + 64);
				if (!scene->objs[counter])
					return (3);
				scene->objs[counter]->height = height;
				scene->objs[counter]->width = width;
				counter++;
			}
			else if (map[y][x] == '1' && (y > 0 && x > 0))
			{
				scene->objs[counter] = make_scene_obj(OBJ_STONE, stone_image, 64*x, 64*y + 64);
				if (!scene->objs[counter])
					return (3);
				scene->objs[counter]->height = height;
				scene->objs[counter]->width = width;
				counter++;
			}
			if (map[y][x] == 'P')
			{
				scene->player_x = x * 64;
				scene->player_y = y * 64;
			}
			if (map[y][x] == 'C')
			{
				scene->chests[chest_counter] = make_chest(mlx, 2,  64*x, 64*y + 64);
				if (!scene->chests[chest_counter])
					return (3);
				scene->chests[chest_counter]->obj->is_render = 0;
				chest_counter++;
			}
			if (map[y][x] == 'S')
			{
				scene->enemies[enemy_counter] = make_enemy(mlx, 64*x, 64*y + 64);
				
				if (!scene->enemies[enemy_counter])
					return (3);
				enemy_counter++;
			}
			x++;
		}
		y++;
	}
	scene->objs[counter] = NULL;
	scene->chests[chest_counter] = NULL;
	scene->enemies[enemy_counter] = NULL;
	return (0);
}

t_scene_obj	*make_scene_obj(t_obj_type t, void *image, int x, int y)
{
	t_scene_obj	*obj;

	obj = malloc(sizeof(t_scene_obj));
	if (!obj)
		return (NULL);
	obj->image = image;
	obj->x = x;
	obj->y = y;
	obj->type = t;
	obj->coll = make_collider(64, 64, &obj->x, &obj->y);
	if (!obj->coll)
		return (free(obj), NULL);
	obj->is_render = 1;
	return (obj);
}
