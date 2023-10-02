/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:41:45 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/02 18:51:25 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
void	player_attack_handler(t_player *player)
{
	if (player->attack_combo == 0)
		add_task(player, ATTACK_1, player->anime->attack_1, 0);
	else if (player->attack_combo == 1)
		add_task(player, ATTACK_2, player->anime->attack_2, 0);
	else if (player->attack_combo == 2)
		add_task(player, ATTACK_3, player->anime->attack_3, 0);
		
	if (player->attack_combo == 2)
		player->attack_combo = 0;
	else
		player->attack_combo++;
}

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
	if (keycode == BUTTON_SPACE)
		player_attack_handler(player);
	// if (keycode == GO_BACK)
	// 	player->x -= PLAYER_SPEED;
	return 0;
}