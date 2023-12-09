/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:43:30 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/09 19:13:00 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy_behavior.h"

static int enemy_is_movement(t_enemy_action action)
{
	return (action == E_MOVE_STRAIGHT ||
			action == E_MOVE_BACK || 
			action == E_MOVE_UP ||
			action == E_MOVE_DOWN);
}

int	enemy_is_able_to_move(t_enemy *enemy, t_scene *scene, t_player *player)
{
	t_enemy_task	*task;
	t_collider		*coll;
	int				inter;
	int				counter;
	
	if (!player || !enemy || !enemy->current_task)
		return (1);
	if (enemy->is_died || player->is_died)
		return (0);
	task = enemy->current_task;
	if (enemy_is_movement(task->action))
	{	
		counter = 0;
		while (scene->enemies[counter])
		{
			coll = scene->enemies[counter]->coll;
			if (coll != enemy->coll && !scene->enemies[counter]->is_died)
			{
				inter = check_intersection(enemy->coll, coll, task->action, ENEMY_MOVE_SPEED);
				if (inter && inter != -1)
					return (0);
			}
			counter++;
		}
	}
	return (1);
}