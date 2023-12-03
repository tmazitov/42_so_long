/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:07:19 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/02 19:58:09 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	*free_player(t_player *player)
{
	if (player->anime)
		free_player_anime(player->anime);
	if (player->coll)
		free_collider(player->coll);
	free(player);
	return (NULL);
}

static void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->last_x = 0;
	player->last_y = 0;
	player->score = 0;
	player->attack_call_down = 0;
	player->last_movement = MOVE_DOWN;
	player->current_task = NULL;
}	

t_player *make_player(void *mlx, int height, int width)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	init_player(player);
	player->height = height;
	player->width = width;
	player->mlx = mlx;
	player->anime = make_player_anime(player);
	if (!player->anime)
		return (free_player(player));
	player->coll = make_collider(64, 64, &player->x, &player->y);
	if (!player->coll)
		return (free_player(player));
	player->health = make_health_bar(mlx, 5);
	if (!player->health)
		return (free_player(player));
	player->hit_box = make_collider(42, 32, &player->x, &player->y);
	player->hit_box = coll_set_align(player->hit_box, 16, 16);
	if (!player->hit_box)
		return (free_player(player));
	printf("success created player!\n");
	return (player);
}