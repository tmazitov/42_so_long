/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_task.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:53:47 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/28 14:02:26 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

static t_enemy_action	calc_enemy_action(t_enemy *enemy)
{
	t_a_point		*next_point;

	if (!enemy->path)
		return (0);
	next_point = enemy->path->points->point;
	printf("next point : %d %d\n", next_point->x, next_point->y);
	if (next_point->x > enemy->x) 
		return (E_MOVE_STRAIGHT);
	else if (next_point->x < enemy->x) 
		return (E_MOVE_BACK);
	else if (next_point->y > enemy->y) 
		return (E_MOVE_UP);
	else if (next_point->y < enemy->y) 
		return (E_MOVE_DOWN);
	return (0);
}

t_enemy_task	*make_enemy_task(t_anime *anime, t_enemy_action act, int dur)
{
	t_enemy_task	*task;

	task = malloc(sizeof(t_enemy_task));
	if (!task)
		return (NULL);
	task->anime = anime;
	task->action = act;
	task->duration = dur; 
	return (task);
}

void	*free_enemy_task(t_enemy_task *task)
{
	if (task)
		free(task);
	return (NULL);
}

void	add_enemy_task(t_enemy *enemy)
{
	t_enemy_action	act;
	t_anime			*anime;
	
	if (enemy->current_task)
		return ;
	anime = NULL;
	act = calc_enemy_action(enemy);
	if (act == 0)
		return ;
	if (act == E_MOVE_BACK || act == E_MOVE_STRAIGHT)
		enemy->last_action = act;
	if (act == E_MOVE_BACK) 
		anime = enemy->anime->idle_left;	
	else if (act == E_MOVE_STRAIGHT) 
		anime = enemy->anime->idle_right;
	else if (act == E_MOVE_UP) 
		anime = enemy->anime->idle_right;
	else if (act == E_MOVE_DOWN) 
		anime = enemy->anime->idle_right;
	enemy->current_task = make_enemy_task(anime, act, 64);
}