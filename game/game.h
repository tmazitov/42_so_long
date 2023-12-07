/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:52:22 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/07 14:00:26 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include <stdlib.h>
#include "../mlx/mlx.h"
#include "player/player.h"
#include "scene/scene.h"
#include "enemy_behavior/enemy_behavior.h"
#include "player_behavior/player_behavior.h"
#include "../utils/printf/ft_printf.h"

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			height;
	int			width;
	t_player	*player;
	t_scene		*scene;
}		t_game;

// GAME

void		*free_game(t_game *game);
t_game		*make_game(int height, int width, char *title);
int			player_control_hook(int keycode, t_game *game);


#endif // GAME_H