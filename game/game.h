/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:52:22 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/09 15:12:51 by tmazitov         ###   ########.fr       */
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
#include "../utils/mlx_font_print/mlx_font_print.h"
typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			height;
	int			width;
	t_player	*player;
	t_scene		*scene;
	t_writer	*writer;
	int			blocker;
}		t_game;

// GAME

void	*free_game(t_game *game);
t_game	*make_game(int height, int width, char *title);
int		feed_game_writer(t_writer *writer);

void	player_exit_handler(t_game *game);
int		player_control_hook(int keycode, t_game *game);
#endif // GAME_H