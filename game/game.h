/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:52:22 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/07 20:19:21 by tmazitov         ###   ########.fr       */
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

void	*free_game(t_game *game);
t_game	*make_game(int height, int width, char *title);

#endif // GAME_H