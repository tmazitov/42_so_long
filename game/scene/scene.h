/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:32:11 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/08 22:45:44 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

#include <stdio.h>
#include <stdlib.h>
#include "../parser/parser.h"
#include "../../mlx/mlx.h"
#include "../../utils/collider/collider.h"

typedef struct s_scene_textures
{
	void	*grass;
}		t_scene_textures;

typedef struct s_tree 
{
	int			x;
	int			y;
	int			height;
	int			width;
	void		*image;
	t_collider	*coll;
}		t_tree;

typedef struct s_scene
{
	char				**raw;
	t_scene_textures	*textures;
	int					width;
	int					height;
	t_tree				**trees;
	int					player_x;
	int					player_y;
}		t_scene;

t_scene *make_scene(void *mlx, char *mapPath, int height, int width);

t_tree	*make_tree(void *image, int x, int y);
int 	feel_tree(void *mlx, char **map, t_scene *scene);
#endif 