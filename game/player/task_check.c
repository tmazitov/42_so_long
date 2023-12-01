/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:30:15 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/01 12:41:56 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int is_attack(t_action action)
{
	return (action == ATTACK_1 ||
			action == ATTACK_2 ||
			action == ATTACK_3);
}

int is_movement(t_action action)
{
	return (action == MOVE_BACK ||
			action == MOVE_DOWN || 
			action == MOVE_STRAIGHT ||
			action == MOVE_UP);
}

static	int	check_objs_intersect(t_player *player, t_scene_obj **objs)
{
	int				counter;
	int				inter;
	t_collider		*coll;
	t_player_task	*task;

	counter = 0;
	task = player->current_task;
	while (objs[counter])
	{
		coll = objs[counter]->coll;
		inter = check_intersection(player->coll, coll, task->action, PLAYER_SPEED);
		if (inter && inter != -1)
			return (0);
		counter++;
	}
	return (1);
}
static	int	check_enemy_intersect(t_player *player, t_enemy **enemies)
{
	int				counter;
	int				inter;
	t_collider		*coll;
	t_player_task	*task;

	counter = 0;
	task = player->current_task;
	while (enemies[counter])
	{
		coll = enemies[counter]->coll;
		inter = check_intersection(player->coll, coll, task->action, PLAYER_SPEED);
		if (inter && inter != -1)
			return (0);
		counter++;
	}
	return (1);
}

int	is_able_to_proccess(t_scene *scene, t_player *player)
{
	t_player_task	*task;
	
	if (!player || !scene || !player->current_task)
		return (1);
	task = player->current_task;
	if (is_attack(task->action))
		return (1);
	if (is_movement(task->action))
	{
		if (task->duration != 64)
			return (1);
		if (check_objs_intersect(player, scene->objs) != 1)
			return (0);
		if (check_enemy_intersect(player, scene->enemies) != 1)
			return (0);
	}
	return (1);
}