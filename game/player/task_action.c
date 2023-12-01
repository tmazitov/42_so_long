/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:34:10 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/01 21:52:17 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	add_task(t_player *player, t_action action, t_anime *anime, int target)
{
	t_player_task *task;
	t_player_task *temp;

	if (task_count(player->current_task) > 3)
		return ;
	task = make_task(action, anime);
	if (!task)
		return ;
	if (target > 0)
		task->duration = target;
	else	
		task->duration = anime->tile_life_time * anime->tile_count;
	if (is_movement(action))
		player->last_movement = action;
	temp = player->current_task;
	while (temp && temp->next)
		temp = temp->next;
	if (temp)
		temp->next = task;
	else
		player->current_task = task;
}

int	execute_action(t_scene *scene, t_player *player, t_player_task *task)
{
	if (task->action == MOVE_STRAIGHT)
	{
		player->x += PLAYER_SPEED;
		return (PLAYER_SPEED);
	}
	else if (task->action == MOVE_BACK)
	{
		player->x -= PLAYER_SPEED;
		return (PLAYER_SPEED);
	}
	else if (task->action == MOVE_UP)
	{
		player->y += PLAYER_SPEED;
		return (PLAYER_SPEED);
	}
	else if (task->action == MOVE_DOWN)
	{
		player->y -= PLAYER_SPEED;
		return (PLAYER_SPEED);
	}
	else if (task->action == ATTACK_1 && 
		task->duration == task->anime->tile_life_time * task->anime->tile_count)
		return (handle_player_attack(player, scene));
	return (1);
}

t_anime	*task_proccess(t_scene *scene, t_player *player)
{
	t_player_task	*task;
	int				is_able_to_proc;

	task = player->current_task;
	is_able_to_proc = is_able_to_proccess(scene, player);
	// printf("player : x=%d y=%d dur=%d\n",player->x, player->y, task->duration);
	if (task->duration > 0 && is_able_to_proc)
		task->duration -= execute_action(scene, player, task);
	else
	{
		player->current_task = task->next;
		if (task->next && task->action != player->current_task->action)
			refresh_anime(task->anime);
		else if (!task->next)
			refresh_anime(task->anime);
		if (is_attack(task->action) && !task->next)
			player->attack_combo = 0;
		if (task && is_movement(task->action)) 
		{
			player->score += 1;
			player->last_x = player->x;
			player->last_y = player->y;
		}
		free_task(task);
	}

	if (!is_able_to_proc)
		return (NULL);
	return task->anime;
}