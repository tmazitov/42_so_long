/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:39:17 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/29 14:34:26 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

t_enemy	*make_enemy(void *mlx, int x, int y)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy) 
		return (NULL);
	enemy->x = x;
	enemy->y = y;
	enemy->coll = make_collider(64, 64, &enemy->x, &enemy->y);
	if (!enemy->coll)
		return (free_enemy(enemy));	
	enemy->anime = make_enemy_anime(mlx);
	if (!enemy->anime)
		return (free_enemy(enemy));
	enemy->last_action = E_MOVE_BACK;
	enemy->path = NULL;
	printf("success enemy create\n");
	enemy->path_counter = PATH_FOUND_CALLDOWN / 2;
	enemy->current_task = NULL;
	enemy->player_score = 0;
	return (enemy);
}

void	*free_enemy(t_enemy *enemy)
{
	if (enemy->anime)
		free_enemy_anime(enemy->anime);
	if (enemy->coll)
		free_collider(enemy->coll);
	free(enemy);
	return (NULL);
}