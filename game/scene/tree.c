/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:20:36 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/09 13:39:00 by tmazitov         ###   ########.fr       */
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
	int		x;
	int		y;
	t_anime	*open_chest;
	t_anime	*close_chest;

	height = 237;
	width = 105;
	height_stone = 51;
	width_stone = 92;
	scene->objs = malloc(sizeof(t_scene_obj *) * (count_of_trees(map) + 1));
	if (!scene->objs)
		return (1);
	tree_image = mlx_xpm_file_to_image(mlx, "textures/tree/tree_4.xpm", &width, &height);
	if (!tree_image)
		return (2);
	stone_image = mlx_xpm_file_to_image(mlx, "textures/tree/tree_2.xpm", &width_stone, &height_stone);
	if (!stone_image)
		return (2);
	open_chest = make_chest_open_anime(mlx, 64, 64);
	if (!open_chest)
		return (2);
	close_chest = make_chest_close_anime(mlx, 64, 64);
	if (!close_chest)
		return (2);
	scene->chest = NULL;
	y = 0;
	counter = 0;
	
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
				// printf("tree : %d %d\n", scene->trees[counter]->x, scene->trees[counter]->y);
				counter++;
			}
			else if (map[y][x] == '1' && (y > 0 && x > 0))
			{
				scene->objs[counter] = make_scene_obj(OBJ_STONE, stone_image, 64*x, 64*y + 64);
				if (!scene->objs[counter])
					return (3);
				scene->objs[counter]->height = height;
				scene->objs[counter]->width = width;
				// printf("tree : %d %d\n", scene->trees[counter]->x, scene->trees[counter]->y);
				counter++;
			}
			if (map[y][x] == 'P')
			{
				scene->player_x = x * 64;
				scene->player_y = y * 64;
			}
			if (map[y][x] == 'C')
			{
				scene->chest = make_chest(2, open_chest, close_chest,  64*x, 64*y + 64);
				if (!scene->chest)
					return (2);
			}
			x++;
		}
		y++;
	}
	scene->objs[counter] = NULL;
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
	return (obj);
}
