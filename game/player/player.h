/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:07:26 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/09 18:59:07 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include <stdlib.h>
# include "../scene/scene.h"
# include "../health_bar/health_bar.h"
# include "../../mlx/mlx.h"
# include "../../utils/anime/anime.h"
# include "../../utils/collider/collider.h"

# define PLAYER_SPEED 		4
# define ATTACK_CALL_DOWN	32

// Player movement buttons
enum t_move_keycode {
	BUTTON_UP 		= 1,
	BUTTON_DOWN 	= 13,
	BUTTON_STRAIGHT = 2,
	BUTTON_BACK		= 0,
	BUTTON_SPACE 	= 49,
	BUTTON_SHIFT 	= 257,
};

// Task action
typedef enum s_action {
	MOVE_STRAIGHT	= 1,
	MOVE_BACK 		= 2,
	MOVE_UP 		= 3,
	MOVE_DOWN 		= 4,
	ATTACK_1		= 5,
	ATTACK_2		= 6,
	ATTACK_3		= 7,
	OPEN_CHEST		= 8,	
	DIE				= 9,	
} 		t_action;

// Task target
typedef struct s_target {
	int	move;
}		t_target;

typedef struct s_player_task
{
	t_action				action;
	t_anime					*anime;
	int						duration;
	struct s_player_task	*next;
}		t_player_task;


// Player animation storage
typedef struct s_player_anime
{
	t_anime		*idle_down;
	t_anime		*idle_right;
	t_anime		*idle_left;
	t_anime		*idle_up;
	
	t_anime		*walk_right;
	t_anime		*walk_left;
	t_anime		*walk_down;	
	t_anime		*walk_up;
	
	t_anime		*attack_down;
	t_anime		*attack_right;
	t_anime		*attack_up;
	t_anime		*attack_left;

	t_anime		*die;
	t_anime		*died;
}		t_player_anime;

// Player structure
typedef struct s_player
{
	void				*mlx;
	int					x;
	int					last_x;
	int					y;
	int					last_y;
	int					width;
	int					height;
	int					attack_call_down;
	int					score;
	int					money;
	int					is_died;
	t_collider			*hit_box;
	t_health_bar		*health;
	t_action			last_movement;
	t_collider			*coll;
	t_player_task		*current_task;
	t_player_anime		*anime;
}		t_player;

// INSTANCE

t_player		*make_player(void *mlx, int height, int width);
void			*free_player(t_player *player);

// ANIME

t_player_anime	*make_player_anime(t_player *player);
void			*free_player_anime(t_player_anime *anime);
int				setup_attack_anime(t_player *player, t_player_anime *player_anime);
int				setup_idle_anime(t_player *player, t_player_anime *player_anime);
int				setup_move_anime(t_player *player, t_player_anime *player_anime);
int				setup_die_anime(t_player *player, t_player_anime *player_anime);
t_anime			*pl_idle_anime(t_player *player);

// TASK

t_player_task	*make_task(t_action action, t_anime *anime);
void			*free_task(t_player_task *task);
void			add_task(t_player *player, t_action action, t_anime *anime, int target);
t_anime			*task_proccess(t_scene *scene, t_player *player);
int				is_able_to_proccess(t_scene *scene, t_player *player);
int 			is_movement(t_action action);
int 			is_attack(t_action action);
int 			task_count(t_player_task *task);
int				handle_player_attack(t_player *player, t_scene *scene);
#endif // !PLAYER_H