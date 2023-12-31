/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:39:24 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 23:09:11 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# include "../../utils/anime/anime.h"
# include "../../utils/collider/collider.h"
# include "../../utils/path/path.h"
# include "../../utils/printf/ft_printf.h"
# include "../health_bar/health_bar.h"
# include <stdlib.h>

# define PATH_FOUND_CALLDOWN 96
# define ENEMY_SPEED 2

typedef enum s_enemy_actions
{
	E_MOVE_STRAIGHT = 1,
	E_MOVE_BACK = 2,
	E_MOVE_UP = 3,
	E_MOVE_DOWN = 4,
	E_DIE = 5,
}					t_enemy_action;

typedef struct s_enemy_anime
{
	t_anime			*idle_right;
	t_anime			*idle_left;
	t_anime			*move_right;
	t_anime			*move_left;
	t_anime			*die;
	t_anime			*died;
	int				die_anime_done;
}					t_enemy_anime;

typedef struct s_enemy_task
{
	t_enemy_action	action;
	t_anime			*anime;
	t_a_point		*target;
	int				duration;
}					t_enemy_task;

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
	int				is_go_back;
}					t_enemy;

// INSTANCE

t_enemy				*make_enemy(void *mlx, int x, int y);
void				*free_enemy(t_enemy *enemy);

// ANIME

t_enemy_anime		*make_enemy_anime(void *mlx);
void				*free_enemy_anime(t_enemy_anime *anime);
t_anime				*make_right_idle_anime(void *mlx);
t_anime				*make_right_move_anime(void *mlx);
t_anime				*make_left_idle_anime(void *mlx);
t_anime				*make_left_move_anime(void *mlx);
t_anime				*make_died_anime(void *mlx);
t_anime				*make_die_anime(void *mlx);

// TASK

t_enemy_task		*make_enemy_task(t_anime *anime, t_enemy_action act,
						t_a_point *target);
void				*free_enemy_task(t_enemy_task *task);
void				add_enemy_task(t_enemy *enemy, t_a_point *target);
void				proc_enemy_task_rev(t_enemy *enemy);
t_anime				*proc_enemy_task(t_enemy *enemy);
t_anime				*enemy_idle_anime(t_enemy *enemy);
#endif