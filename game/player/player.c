/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:07:19 by tmazitov          #+#    #+#             */
/*   Updated: 2023/09/30 22:04:36 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	*free_player(t_player *player)
{
	if (player->anime)
		free_player_anime(player->anime);
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
	player->height = height;
	player->width = width;
	player->mlx = mlx;
	player->anime = make_player_anime(player);
	player->current_task = NULL;
	if (!player->anime)
		return (free_player(player));
	printf("success created player!\n");
	return (player);
}