/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_attack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:26:55 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/02 19:24:59 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static t_enemy	*get_enemy_to_hit(t_player *player, t_scene *scene)
{	
	int			counter;
	t_action	act;
	t_enemy		**enemies;
	t_collider	*coll;

	if (!player || !scene)
		return (NULL);
	counter = 0;
	act = player->last_movement;
	enemies = scene->enemies;
	while (enemies[counter])
	{
		if (!enemies[counter]->is_died)
		{
			coll = enemies[counter]->coll;
			if (check_intersection(player->coll, coll, act, PLAYER_SPEED))
				return (enemies[counter]);	
		}
		counter++;
	}
	return (NULL);
}

int	handle_player_attack(t_player *player, t_scene *scene)
{
	t_enemy	*enemy;

	enemy = get_enemy_to_hit(player, scene);
	if (!enemy)
		return (1);
	hb_update(enemy->health, enemy->health->current - 1);
	if (enemy->health->current == 0)
		enemy->is_died = 1;
	return (1);
}