/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:41:45 by tmazitov          #+#    #+#             */
/*   Updated: 2023/09/30 23:06:10 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int	player_control_hook(int keycode, t_player *player)
{
	printf("keycode: %d\n", keycode);
	// if (keycode == GO_UP)
	// 	player->y += PLAYER_SPEED;
	// if (keycode == GO_DOWN)
	// 	player->y -= PLAYER_SPEED;
	if (keycode == BUTTON_STRAIGHT)
		add_task(player, MOVE_STRAIGHT, player->anime->walk, 64);
	if (keycode == BUTTON_BACK)
		add_task(player, MOVE_BACK, player->anime->walk, 64);
	if (keycode == BUTTON_UP)
		add_task(player, MOVE_UP, player->anime->walk, 64);
	if (keycode == BUTTON_DOWN)
		add_task(player, MOVE_DOWN, player->anime->walk, 64);
	// if (keycode == GO_BACK)
	// 	player->x -= PLAYER_SPEED;
	return 0;
}