/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_task.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:53:47 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 23:08:32 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

static t_enemy_action	calc_enemy_action(t_enemy *enemy, t_a_point *target)
{
	if (!enemy->path)
		return (0);
	if (enemy->is_died)
		return (E_DIE);
	else if (target->x > enemy->x)
		return (E_MOVE_STRAIGHT);
	else if (target->x < enemy->x)
		return (E_MOVE_BACK);
	else if (target->y > enemy->y)
		return (E_MOVE_UP);
	else if (target->y < enemy->y)
		return (E_MOVE_DOWN);
	return (0);
}

t_enemy_task	*make_enemy_task(t_anime *a, t_enemy_action act, t_a_point *t)
{
	t_enemy_task	*task;

	task = malloc(sizeof(t_enemy_task));
	if (!task)
		return (NULL);
	task->anime = a;
	task->action = act;
	task->duration = a->tile_count * a->tile_life_time;
	task->target = t;
	return (task);
}

void	*free_enemy_task(t_enemy_task *task)
{
	if (task)
		free(task);
	return (NULL);
}

static	t_anime	*calc_task_anime(t_enemy *enemy, t_enemy_action act)
{
	if (act == E_MOVE_BACK)
		return (enemy->anime->move_left);
	else if (act == E_MOVE_STRAIGHT)
		return (enemy->anime->move_right);
	else if (act == E_MOVE_UP && enemy->last_action == E_MOVE_STRAIGHT)
		return (enemy->anime->move_right);
	else if (act == E_MOVE_UP && enemy->last_action == E_MOVE_BACK)
		return (enemy->anime->move_left);
	else if (act == E_MOVE_DOWN && enemy->last_action == E_MOVE_STRAIGHT)
		return (enemy->anime->move_right);
	else if (act == E_MOVE_DOWN && enemy->last_action == E_MOVE_BACK)
		return (enemy->anime->move_left);
	else if (act == E_DIE)
		return (enemy->anime->die);
	return (NULL);
}

void	add_enemy_task(t_enemy *enemy, t_a_point *target)
{
	t_enemy_action	act;
	t_anime			*anime;

	if (enemy->current_task)
		return ;
	anime = NULL;
	act = calc_enemy_action(enemy, target);
	if (act == 0)
		return ;
	if (act == E_MOVE_BACK || act == E_MOVE_STRAIGHT)
		enemy->last_action = act;
	anime = calc_task_anime(enemy, act);
	enemy->current_task = make_enemy_task(anime, act, target);
}
