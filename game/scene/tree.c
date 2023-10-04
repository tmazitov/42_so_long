/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:20:36 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/04 13:47:43 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int feel_tree(void *mlx, t_scene *scene, int count)
{
	void	*image;
	int		height;
	int		width;
	
	height = 237;
	width = 105;
	scene->trees = malloc(sizeof(t_tree *) * (count + 1));
	if (!scene->trees)
		return (1);
	image = mlx_xpm_file_to_image(mlx, "textures/tree.xpm", &width, &height);
	if (!image)
		return (2);
	scene->trees[0] = make_tree(image, 200, 200);
	if (!scene->trees[0])
		return (3);
	scene->trees[count] = NULL;
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
	return (tree);
}

