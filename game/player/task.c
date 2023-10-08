/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:44:50 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/08 17:11:03 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	*free_task(t_player_task *task)
{
	free(task);
	return (NULL);
}

int task_count(t_player_task *task)
{
	if (!task)
		return (0);
	if (task->next)
		return (task_count(task->next) + 1);
	return (1);
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

	if (task_count(player->current_task) > 3)
		return ;
	task = make_task(action, anime);
	if (!task)
		return ;
	if (target > 0)
		task->duration = target;
	else	
		task->duration = anime->tile_life_time * anime->tile_count;
	// printf("task duration: %d\n",task->duration);
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
	return (1);
}

int is_attack(t_action action){
	return (action == ATTACK_1 ||
			action == ATTACK_2 ||
			action == ATTACK_3);
}

int is_movement(t_action action){
	return (action == MOVE_BACK ||
			action == MOVE_DOWN || 
			action == MOVE_STRAIGHT ||
			action == MOVE_UP);
}

int	is_able_to_proccess(t_scene *scene, t_player *player)
{
	t_player_task	*task;
	t_collider		*coll;
	int				tree_ctn;
	int				inter;
	
	task = player->current_task;
	if (is_attack(task->action))
		return (1);
	if (is_movement(task->action))
	{
		tree_ctn = 0;
		while (scene->trees[tree_ctn])
		{
			coll = scene->trees[tree_ctn]->coll;
			inter = check_intersection(player->coll, coll, task->action, PLAYER_SPEED);
			if (inter == -1)
			{
				tree_ctn++;
				continue;
			}
			if (inter)
				return (0);
			printf("\ttree: x=%d y=%d\n", *coll->x, *coll->y);
			printf("\tintersection : %d\t task: %d\n", inter, task->action);
			// if (inter && inter == (int)task->action)
			// 	return (0);
			tree_ctn++;
		}
	}
	return (1);
}

t_anime	*task_proccess(t_scene *scene, t_player *player)
{
	t_player_task	*task;
	int				is_able_to_proc;

	task = player->current_task;
	is_able_to_proc = is_able_to_proccess(scene, player);
	printf("player : x=%d y=%d dur=%d\n",player->x, player->y, task->duration);
	if (task->duration > 0 && is_able_to_proc)
		task->duration -= execute_action(player, task);
	else
	{
		player->current_task = task->next;
		if (task->next && task->action != player->current_task->action)
			refresh_anime(task->anime);
		else if (!task->next)
			refresh_anime(task->anime);
		if (is_attack(task->action) && !task->next)
			player->attack_combo = 0;
		free_task(task);
	}
	if (!is_able_to_proc)
		return (NULL);
	return task->anime;
}		