/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_behavior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:58:47 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/07 15:59:34 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_behavior.h"
#include <stdio.h>
#include <stdlib.h>

void	player_attack_handler(t_player *player)
{
	if (player->attack_call_down != 0)
		return ;
	if (player->last_movement == MOVE_DOWN)
		add_task(player, ATTACK_1, player->anime->attack_up, 0);
	else if (player->last_movement == MOVE_UP)
		add_task(player, ATTACK_1, player->anime->attack_down, 0);
	else if (player->last_movement == MOVE_STRAIGHT)
		add_task(player, ATTACK_1, player->anime->attack_right, 0);
	else if (player->last_movement == MOVE_BACK)
		add_task(player, ATTACK_1, player->anime->attack_left, 0);
}

int	player_open_chest_handler(t_game *game)
{
	int			counter;
	int			chest_money;
	t_chest		*chest;
	t_player	*player;

	player = game->player;
	counter = 0;
	chest_money = 0;
	chest = NULL;
	while (game->scene->chests[counter])
	{
		chest = game->scene->chests[counter];
		if (check_intersection(chest->obj->coll, player->coll, OPEN_CHEST, 0))
			chest_money = toggle_chest(chest);
		counter++;
	}
	game->player->money += chest_money;
	return (chest_money);
}

void	player_exit_handler(t_game *game)
{
	t_collider	*exit_coll;
	t_collider	*player_coll;

	player_coll = game->player->coll;
	exit_coll = game->scene->exit->obj->coll;
	if (check_intersection(player_coll, exit_coll, OPEN_CHEST, 0))
	{
		free_game(game);
		exit(EXIT_SUCCESS);
	}
}

void	shift_handler(t_game *game)
{
	if (player_open_chest_handler(game))
		return ;
	player_exit_handler(game);
}

int	player_control_hook(int keycode, t_game *game)
{
	ft_printf("keycode: %d\n", keycode);
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
		shift_handler(game);
	return 0;
}