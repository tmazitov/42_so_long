/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:52:22 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/02 19:42:27 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include <stdlib.h>
#include "../mlx/mlx.h"
#include "player/player.h"
#include "scene/scene.h"

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_player	*player;
	t_scene		*scene;
}		t_game;

// GAME

void		*free_game(t_game *game);
t_game		*make_game(int height, int width, char *title);
int			player_control_hook(int keycode, t_game *game);

t_anime 	*enemy_handle_move(t_player *player, t_scene *scene, t_enemy *enemy);
t_anime		*exec_enemy_behavior(t_player *player, t_scene *scene, t_enemy *enemy);
void		enemy_handle_attack(t_enemy *enemy, t_player *player);
int			enemy_is_able_to_move(t_enemy *enemy, t_scene *scene, t_player *player);
#endif // GAME_H