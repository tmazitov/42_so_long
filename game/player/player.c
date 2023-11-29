/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:07:19 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/29 12:14:02 by tmazitov         ###   ########.fr       */
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

t_player *make_player(void *mlx, int height, int width)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = 0;
	player->y = 0;
	player->last_x = 0;
	player->last_y = 0;
	player->score = 0;
	player->height = height;
	player->width = width;
	player->mlx = mlx;
	player->anime = make_player_anime(player);
	if (!player->anime)
		return (free_player(player));
	player->current_task = NULL;
	player->attack_combo = 0;
	player->coll = make_collider(64, 64, &player->x, &player->y);
	if (!player->coll)
		return (free_player(player));
	player->last_movement = MOVE_DOWN; 
	printf("success created player!\n");
	return (player);
}