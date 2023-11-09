/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:32:11 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/13 19:01:25 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

#include <stdio.h>
#include <stdlib.h>
#include "../parser/parser.h"
#include "../../mlx/mlx.h"
#include "../../utils/collider/collider.h"

typedef enum s_obj_type{
	OBJ_TREE	= 1,
	OBJ_STONE	= 2,
}		t_obj_type;

typedef struct s_scene_textures
{
	void	*grass;
}		t_scene_textures;

typedef struct s_scene_obj 
{
	int			x;
	int			y;
	int			height;
	int			width;
	void		*image;
	t_obj_type	type;
	t_collider	*coll;
}		t_scene_obj;


typedef struct s_scene
{
	char				**raw;
	t_scene_textures	*textures;
	int					width;
	int					height;
	t_scene_obj 		**objs;
	int					player_x;
	int					player_y;
}		t_scene;

t_scene *make_scene(void *mlx, char *mapPath, int height, int width);


t_scene_obj	*make_scene_obj(t_obj_type t, void *image, int x, int y);
int 	feel_tree(void *mlx, char **map, t_scene *scene);
#endif 