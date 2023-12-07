/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:19:34 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/07 13:56:30 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy_behavior.h"

static void	enemy_make_hit(t_player *player)
{
	hb_update(player->health, player->health->current - 1);
}

void	enemy_handle_attack(t_enemy *enemy, t_player *player)
{
	// 1. Make hit
	// 2. Start the task reverse -> return to the last position with animation
	enemy_make_hit(player);
	proc_enemy_task_rev(enemy);	
}