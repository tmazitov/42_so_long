/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:32:11 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/26 20:27:07 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

#include <stdio.h>
#include <stdlib.h>
#include "../parser/parser.h"
#include "../enemy/enemy.h"
#include "../../mlx/mlx.h"
#include "../../utils/collider/collider.h"
#include "../../utils/anime/anime.h"
#include "../../utils/path/path.h"

typedef enum s_obj_type{
	OBJ_TREE	= 1,
	OBJ_STONE	= 2,
	OBJ_CHEST	= 3,
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
	int			is_render;
	t_obj_type	type;
	t_collider	*coll;
}		t_scene_obj;

typedef	struct s_chest
{
	int			x;
	int			y;
	int			money;
	int			is_open;
	int			open_in_proc;
	int			anime_in_proc;
	t_anime		*open_anime;
	t_anime		*close_anime;
	t_scene_obj	*obj;
}		t_chest;

typedef struct s_scene
{
	char				**raw;
	t_scene_textures	*textures;
	int					width;
	int					height;
	t_enemy				**enemies;
	t_chest				**chests;
	t_scene_obj 		**objs;
	int					player_x;
	int					player_y;
	t_point_list		*game_objs_points;
}		t_scene;

t_scene *make_scene(void *mlx, char *mapPath, int height, int width);


t_scene_obj	*make_scene_obj(t_obj_type t, void *image, int x, int y);
int 		feel_tree(void *mlx, char **map, t_scene *scene);

t_chest		*make_chest(void *mlx, unsigned int money, int x, int y);
void		*free_chest(t_chest *chest);
void		*render_chest(t_chest *chest);
int			toggle_chest(t_chest *chest);

t_anime	*make_chest_close_anime(void *mlx, int height, int width);
t_anime	*make_chest_open_anime(void *mlx, int height, int width);

#endif 