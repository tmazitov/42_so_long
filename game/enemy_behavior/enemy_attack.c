/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:19:34 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/09 19:13:54 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy_behavior.h"

static void	enemy_make_hit(t_player *player)
{
	hb_update(player->health, player->health->current - 1);
}

static void player_die_handler(t_player	*player)
{
	t_player_task	*task;
	
	if (player->health->current != 0)
		return ;
	if (player->current_task)
		free_task(player->current_task);
	task = make_task(DIE, player->anime->die);
	if (!task)
		return ;
	task->duration = task->anime->tile_count * task->anime->tile_life_time;
	player->current_task = task;
	player->is_died = 1;
}

void	enemy_handle_attack(t_enemy *enemy, t_player *player)
{
	enemy_make_hit(player);
	player_die_handler(player);
	proc_enemy_task_rev(enemy);	
}