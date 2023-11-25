/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:39:24 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/25 18:28:03 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMY_H
# define ENUMY_H

#include <stdlib.h>
#include "../../utils/collider/collider.h"
#include "../../utils/anime/anime.h"
#include "../scene/scene.h"
#include "../player/player.h"

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
}		t_enemy_anime;

typedef struct s_enemy
{
	int				x;
	int				y;
	int				health;
	t_enemy_action	last_action;
	t_collider		*coll;
	t_enemy_anime	*anime;
}		t_enemy;

// INSTANCE
t_enemy			*make_enemy(void *mlx, int x, int y);
void			*free_enemy(t_enemy *enemy);
	
// ANIME
t_enemy_anime	*make_enemy_anime(void *mlx);
void			*free_enemy_anime(t_enemy_anime	*anime);
t_anime			*make_right_idle_anime(void *mlx, int height, int width);
t_anime			*make_left_idle_anime(void *mlx, int height, int width);
t_anime_tile	*enemy_next_tile(t_enemy *enemy);

// BEHAVIOR
void			exec_enemy_behavior(t_player *player, t_scene* scene, t_enemy *enemy);

#endif 