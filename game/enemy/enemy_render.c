/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:49:35 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/25 22:00:47 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

t_anime_tile *enemy_next_tile(t_enemy *enemy)
{
	if (enemy->last_action == E_MOVE_BACK) 
		return get_next_tile(enemy->anime->idle_left);
	if (enemy->last_action == E_MOVE_STRAIGHT)
		return get_next_tile(enemy->anime->idle_right);
	return (NULL);
}