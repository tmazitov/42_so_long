/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:07:10 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/01 13:00:56 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

static void	enemy_move_handler(t_enemy *enemy)
{
	t_enemy_task	*task;
	
	task = enemy->current_task;
	if (task->action == E_MOVE_BACK && enemy->x != task->target->x)
		enemy->x -= ENEMY_MOVE_SPEED;
	else if (task->action == E_MOVE_STRAIGHT && enemy->x != task->target->x)
		enemy->x += ENEMY_MOVE_SPEED;
	else if (task->action == E_MOVE_UP && enemy->y != task->target->y)
		enemy->y += ENEMY_MOVE_SPEED;
	else if (task->action == E_MOVE_DOWN && enemy->y != task->target->y)
		enemy->y -= ENEMY_MOVE_SPEED;
}

static int enemy_is_movement(t_enemy_task *task) 
{
	return (task->action == E_MOVE_BACK ||
		task->action == E_MOVE_STRAIGHT ||
		task->action == E_MOVE_DOWN ||
		task->action == E_MOVE_UP) ;
}

t_anime *enemy_idle_anime(t_enemy *enemy)
{
	if (enemy->last_action == E_MOVE_BACK)
		return (enemy->anime->idle_left);
	return (enemy->anime->idle_right);
}

t_anime	*proc_enemy_task(t_enemy *enemy)
{
	t_anime			*anime;
	t_enemy_task	*task;
	
	if (!enemy)
		return (NULL);
	task = enemy->current_task;
	if (!task || !enemy->path) 
		return (enemy_idle_anime(enemy));
	anime = task->anime;
	if (enemy_is_movement(task))
		enemy_move_handler(enemy);
	task->duration -= 1;
	if (task->duration == 0)
	{
		refresh_anime(anime);
		free_enemy_task(task);
		enemy->current_task = NULL;
	}
	return (anime);
}
