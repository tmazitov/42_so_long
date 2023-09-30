/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:44:50 by tmazitov          #+#    #+#             */
/*   Updated: 2023/09/30 23:07:03 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	*free_task(t_player_task *task)
{
	free(task);
	return (NULL);
}

t_player_task	*make_task(t_action action, t_anime *anime)
{
	t_player_task	*task;

	task = malloc(sizeof(t_player_task));
	if (!task)
		return (NULL);
	task->anime = anime;
	task->action = action;
	task->next = NULL;
	return (task);
}

void	add_task(t_player *player, t_action action, t_anime *anime, int target)
{
	t_player_task *task;
	t_player_task *temp;

	task = make_task(action, anime);
	if (!task)
		return ;
	if (target > 0)
		task->duration = target;
	else	
		task->duration = anime->tile_life_time * anime->tile_count;
	temp = player->current_task;
	while (temp && temp->next)
		temp = temp->next;
	if (temp)
		temp->next = task;
	else
		player->current_task = task;
}

int	execute_action(t_player *player, t_player_task *task)
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
	return (0);
}

t_anime	*task_proccess(t_player *player)
{
	t_player_task	*task;

	task = player->current_task;
	if (task->duration > 0)
		task->duration -= execute_action(player, task);
	else
	{
		player->current_task = task->next;
		if (task->next && task->action != player->current_task->action)
			refresh_anime(task->anime);
		free_task(task);
	}

	return task->anime;
}