/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:39:24 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/01 21:54:11 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

#include <stdlib.h>
#include "../health_bar/health_bar.h"
#include "../../utils/collider/collider.h"
#include "../../utils/anime/anime.h"
#include "../../utils/path/path.h"

# define PATH_FOUND_CALLDOWN 	128
# define ENEMY_MOVE_SPEED		1

typedef enum s_enemy_actions {
	E_MOVE_STRAIGHT	= 1,
	E_MOVE_BACK 	= 2,
	E_MOVE_UP 		= 3,
	E_MOVE_DOWN 	= 4,
}		t_enemy_action;

typedef	struct s_enemy_anime
{
	t_anime	*idle_right;
	t_anime	*idle_left;
	t_anime *move_right;
	t_anime *move_left;
}		t_enemy_anime;

typedef struct s_enemy_task
{
	t_enemy_action			action;
	t_anime					*anime;
	t_a_point				*target;
	int						duration;
}		t_enemy_task;

typedef struct s_enemy
{
	int				x;
	int				y;
	t_path			*path;
	t_health_bar	*health;
	t_enemy_action	last_action;
	t_collider		*coll;
	t_collider		*hit_box;
	t_enemy_anime	*anime;
	t_enemy_task	*current_task;
	int				path_counter;
	int				player_score;
	int				is_died;
}		t_enemy;


// INSTANCE
t_enemy			*make_enemy(void *mlx, int x, int y);
void			*free_enemy(t_enemy *enemy);
	
// ANIME
t_enemy_anime	*make_enemy_anime(void *mlx);
void			*free_enemy_anime(t_enemy_anime	*anime);
t_anime			*make_right_idle_anime(void *mlx, int height, int width);
t_anime			*make_right_move_anime(void *mlx, int height, int width);
t_anime			*make_left_idle_anime(void *mlx, int height, int width);
t_anime			*make_left_move_anime(void *mlx, int height, int width);
t_anime_tile	*enemy_next_tile(t_enemy *enemy);

// TASK

t_enemy_task	*make_enemy_task(t_anime *a, t_enemy_action act, int dur, t_a_point *t);
void			*free_enemy_task(t_enemy_task *task);
void			add_enemy_task(t_enemy *enemy, t_a_point *target);

t_anime			*proc_enemy_task(t_enemy *enemy);
t_anime 		*enemy_idle_anime(t_enemy *enemy);
#endif 