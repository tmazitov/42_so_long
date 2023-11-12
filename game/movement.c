/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:43:53 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/09 13:44:09 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	player_attack_handler(t_player *player)
{

	if (player->last_movement == MOVE_DOWN)
		add_task(player, ATTACK_1, player->anime->attack_up, 0);
	else if (player->last_movement == MOVE_UP)
		add_task(player, ATTACK_1, player->anime->attack_down, 0);
	else if (player->last_movement == MOVE_STRAIGHT)
		add_task(player, ATTACK_1, player->anime->attack_right, 0);
	else if (player->last_movement == MOVE_BACK)
		add_task(player, ATTACK_1, player->anime->attack_left, 0);

}

void	player_open_chest_handler(t_game *game)
{
	if (game->scene->chest)
	{
		toggle_chest(game->scene->chest);
	}
}

int	player_control_hook(int keycode, t_game *game)
{
	printf("keycode: %d\n", keycode);
	t_player	*player;

	player = game->player;
	if (keycode == BUTTON_STRAIGHT)
		add_task(player, MOVE_STRAIGHT, player->anime->walk_right, 64);
	if (keycode == BUTTON_BACK)
		add_task(player, MOVE_BACK, player->anime->walk_left, 64);
	if (keycode == BUTTON_UP)
		add_task(player, MOVE_UP, player->anime->walk_down, 64);
	if (keycode == BUTTON_DOWN)
		add_task(player, MOVE_DOWN, player->anime->walk_up, 64);
	if (keycode == BUTTON_SPACE)
		player_attack_handler(player);
	if (keycode == BUTTON_SHIFT)
		player_open_chest_handler(game);
	return 0;
}