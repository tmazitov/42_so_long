/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:20:36 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/08 22:56:16 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int feel_tree(void *mlx, char **map, t_scene *scene)
{
	void	*image;
	int		height;
	int		width;
	int		counter;
	int		x;
	int		y;

	height = 237;
	width = 105;
	scene->trees = malloc(sizeof(t_tree *) * (count_of_trees(map) + 1));
	if (!scene->trees)
		return (1);
	image = mlx_xpm_file_to_image(mlx, "textures/tree.xpm", &width, &height);
	if (!image)
		return (2);
	y = 0;
	counter = 0;
	
	while (map[y])
	{
		x = 0;
		printf("raw: %s\n", map[y]);
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				scene->trees[counter] = make_tree(image, 64*x, 64*y + 64);
				if (!scene->trees[counter])
					return (3);
				scene->trees[counter]->height = height;
				scene->trees[counter]->width = width;
				// printf("tree : %d %d\n", scene->trees[counter]->x, scene->trees[counter]->y);
				counter++;
			}
			if (map[y][x] == 'P')
			{
				scene->player_x = x * 64;
				scene->player_y = y * 64;
			}
			x++;
		}
		y++;
	}
	scene->trees[counter] = NULL;
	return (0);
}

t_tree	*make_tree(void *image, int x, int y)
{
	t_tree	*tree;

	tree = malloc(sizeof(t_tree));
	if (!tree)
		return (NULL);
	tree->image = image;
	tree->x = x;
	tree->y = y;
	tree->coll = make_collider(64, 64, &tree->x, &tree->y);
	if (!tree->coll)
		return (free(tree), NULL);
	return (tree);
}

