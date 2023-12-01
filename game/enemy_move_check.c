/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:43:30 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/01 13:03:05 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// int is_attack(t_action action)
// {
// 	return (action == ATTACK_1 ||
// 			action == ATTACK_2 ||
// 			action == ATTACK_3);
// }

static int enemy_is_movement(t_enemy_action action)
{
	return (action == E_MOVE_STRAIGHT ||
			action == E_MOVE_BACK || 
			action == E_MOVE_UP ||
			action == E_MOVE_DOWN);
}

int	enemy_is_able_to_move(t_enemy *enemy, t_player *player)
{
	t_enemy_task	*task;
	int				inter;
	
	if (!player || !enemy || !enemy->current_task)
		return (1);
	task = enemy->current_task;
	if (enemy_is_movement(task->action))
	{	
		inter = check_intersection(enemy->coll, player->coll, task->action, ENEMY_MOVE_SPEED);
		if (inter && inter != -1)
			return (0);
	}
	return (1);
}