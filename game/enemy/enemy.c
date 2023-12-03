/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:39:17 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/03 20:14:49 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

static	void	set_default_values(t_enemy *enemy)
{
	enemy->path = NULL;
	enemy->health = NULL;
	enemy->anime = NULL;
	enemy->coll = NULL;
	enemy->hit_box	= NULL;
	enemy->anime = NULL;
	enemy->current_task = NULL;
	enemy->player_score = 0;
	enemy->is_died = 0;
	enemy->is_go_back = 0;
	enemy->last_action = E_MOVE_BACK;
	enemy->path_counter = PATH_FOUND_CALLDOWN / 2 ;
}

t_enemy	*make_enemy(void *mlx, int x, int y)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy) 
		return (NULL);
	set_default_values(enemy);
	enemy->x = 64 * x;
	enemy->y =  64 * (y + 1);
	enemy->coll = make_collider(64, 64, &enemy->x, &enemy->y);
	if (!enemy->coll)
		return (free_enemy(enemy));	
	enemy->hit_box = make_collider(32, 32, &enemy->x, &enemy->y);
	enemy->hit_box = coll_set_align(enemy->hit_box, 16, 16);
	if (!enemy->hit_box)
		return (free_enemy(enemy));	
	enemy->anime = make_enemy_anime(mlx);
	if (!enemy->anime)
		return (free_enemy(enemy));
	printf("success enemy create\n");
	enemy->health = make_health_bar(mlx, 3);
	if (!enemy->health)
		return (free_enemy(enemy));
	return (enemy);
}

void	*free_enemy(t_enemy *enemy)
{
	if (!enemy)
		return (NULL);
	if (enemy->anime)
		free_enemy_anime(enemy->anime);
	printf("free enemy coll\n");
	if (enemy->coll)
		free_collider(enemy->coll);
	printf("free enemy hit box\n");
	if (enemy->hit_box)
		free_collider(enemy->hit_box);
	if (enemy->health)
		free_health_bar(enemy->health);
	if (enemy->path)
		free_path(enemy->path);
	if (enemy->current_task)
		free_enemy_task(enemy->current_task);
	free(enemy);
	return (NULL);
}