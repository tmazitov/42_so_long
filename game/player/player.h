/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:07:26 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/29 12:27:42 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include <stdlib.h>
# include "../scene/scene.h"
# include "../../mlx/mlx.h"
# include "../../utils/anime/anime.h"
# include "../../utils/collider/collider.h"

# define PLAYER_SPEED 2

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
	int					attack_combo;
	int					score;
	t_action			last_movement;
	t_collider			*coll;
	t_player_task		*current_task;
	t_player_anime		*anime;
}		t_player;

// Player

t_player		*make_player(void *mlx, int height, int width);
void			*free_player(t_player *player);

// Player animation

t_player_anime	*make_player_anime(t_player *player);
void			*free_player_anime(t_player_anime *anime);
int				setup_attack_anime(t_player *player, t_player_anime *player_anime);


// Player tasks

void			add_task(t_player *player, t_action action, t_anime *anime, int target);
t_anime			*task_proccess(t_scene *scene, t_player *player);

#endif // !PLAYER_H