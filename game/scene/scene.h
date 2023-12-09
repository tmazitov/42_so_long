/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:32:11 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/09 19:57:14 by tmazitov         ###   ########.fr       */
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
#include "../../utils/image/image.h"

typedef enum s_obj_type{
	OBJ_TREE	= 1,
	OBJ_SHRUB	= 2,
	OBJ_CHEST	= 3,
	OBJ_EXIT	= 4,
}		t_obj_type;

typedef struct s_scene_textures
{
	t_image	*grass;
	t_image	*tree;
	t_image	*shrub;
	t_image	**roads;
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

typedef	struct s_exit
{
	int			x;
	int			y;
	t_scene_obj	*obj;
}		t_exit;

typedef struct s_scene
{
	void				*mlx;
	char				**raw;
	t_scene_textures	*textures;
	int					width;
	int					height;
	t_enemy				**enemies;
	t_chest				**chests;
	t_scene_obj 		**objs;
	int					player_x;
	int					player_y;
	t_exit				*exit;
	int					exit_x;
	int					exit_y;
	t_point_list		*game_objs_points;
	t_path				*player_way;
}		t_scene;

typedef enum s_road_tile{
	ROAD_NONE_BOT	= 0,
	ROAD_NONE_TOP	= 12,
	ROAD_NONE_LEFT	= 21,
	ROAD_NONE_RIGHT	= 19,
	ROAD_TOP_TOP	= 6,
	ROAD_TOP_RIGHT  = 1,
	ROAD_TOP_LEFT	= 3,
	ROAD_BOT_RIGHT  = 13,
	ROAD_BOT_LEFT	= 15,
	ROAD_RIGHT_RIGHT= 20,
}		t_road_tile;

// SCENE INSTANCE

t_scene				*make_scene(void *mlx, t_map *map, int height, int width);
void				*free_scene(t_scene *scene);

// SCENE FEEL

int 				feel_scene(void *mlx, t_map *map, t_scene *scene);
int					feel_chests(void *mlx, t_map *map, t_scene *scene);
int					feel_enemies(void *mlx, t_map *map, t_scene *scene);
int					feel_trees(t_map *map, t_scene *scene);
int					feel_player_exit(t_map *map, t_scene *scene);
int					feel_player_pos(t_map *map, t_scene *scene);

// SCENE TEXTURES

t_scene_textures	*make_scene_textures(void *mlx);
int					make_road_textures(void *mlx, t_scene_textures *t);
void				*free_scene_textures(t_scene_textures *t);

// SCENE OBJS

t_scene_obj			*make_scene_obj(t_obj_type t, void *image, int x, int y);
t_scene_obj			*make_tree(t_scene *scene, int is_border, int x, int y);
void				*free_scene_obj(t_scene_obj *obj);

// CHEST INSTANCE

t_chest				*make_chest(void *mlx, unsigned int money, int x, int y);
void				*free_chest(t_chest *chest);
void				*render_chest(t_chest *chest);
int					toggle_chest(t_chest *chest);

// CHEST ANIME

t_anime	*make_chest_close_anime(void *mlx, int height, int width);
t_anime	*make_chest_open_anime(void *mlx, int height, int width);

// EXIT INSTANCE

t_exit	*make_exit(int x, int y);
void	*free_exit(t_exit *exit);

#endif 