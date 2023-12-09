/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:10:20 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/09 18:55:57 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	*free_player_anime(t_player_anime *anime)
{
	if (anime->idle_down)
		free_anime(anime->idle_down);
	if (anime->idle_up)
		free_anime(anime->idle_up);
	if (anime->idle_right)
		free_anime(anime->idle_right);
	if (anime->walk_left)
		free_anime(anime->walk_left);
	if (anime->walk_right)
		free_anime(anime->walk_right);
	if (anime->attack_up)
		free_anime(anime->attack_up);
	if (anime->attack_down)
		free_anime(anime->attack_down);
	if (anime->attack_right)
		free_anime(anime->attack_right);
	if (anime->attack_left)
		free_anime(anime->attack_left);
	if (anime->die)
		free_anime(anime->die);
	if (anime->died)
		free_anime(anime->died);
	free(anime);
	return (NULL);
}

void	init_player_anime(t_player_anime *anime)
{
	anime->die = NULL;
	anime->died = NULL;
	anime->idle_down = NULL;
	anime->idle_right = NULL;
	anime->idle_left = NULL;
	anime->idle_up = NULL;
	anime->walk_right = NULL;
	anime->walk_left = NULL;
	anime->walk_down = NULL;	
	anime->walk_up = NULL;
	anime->attack_down = NULL;
	anime->attack_right = NULL;
	anime->attack_up = NULL;
	anime->attack_left = NULL;
}

t_anime	*pl_idle_anime(t_player *player)
{
	t_anime	*anime;

	if (player->is_died)
		return (player->anime->died);
	anime = NULL;
	if (player->last_movement == MOVE_DOWN)
		anime = player->anime->idle_up;
	else if (player->last_movement == MOVE_UP)
		anime = player->anime->idle_down;
	else if (player->last_movement == MOVE_STRAIGHT)
		anime = player->anime->idle_right;
	else if (player->last_movement == MOVE_BACK)
		anime = player->anime->idle_left;
	return (anime);
}

t_player_anime	*make_player_anime(t_player *player)
{
	t_player_anime	*player_anime;
	void			*mlx;
	int				height;
	int				width;

	player_anime = malloc(sizeof(t_player_anime));
	if (!player_anime)
		return (NULL);
	init_player_anime(player_anime);
	height = player->height;
	width = player->width;
	mlx = player->mlx;
	if (setup_idle_anime(player, player_anime) != 0)
		return (free_player_anime(player_anime));
	if (setup_move_anime(player, player_anime) != 0)
		return (free_player_anime(player_anime));
	if (setup_attack_anime(player, player_anime) != 0)
		return (free_player_anime(player_anime));
	if (setup_die_anime(player, player_anime) != 0)
		return (free_player_anime(player_anime));
	return (player_anime);
}

