/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_anime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:53:39 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/29 22:38:04 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

static int	feel_enemy_anime(void *mlx, t_enemy_anime *anime)
{
	anime->idle_left = make_left_idle_anime(mlx, 64, 64);
	if (!anime->idle_left)
		return (1);
	anime->idle_right = make_right_idle_anime(mlx, 64, 64);
	if (!anime->idle_right)
		return (1);
	anime->move_left = make_left_move_anime(mlx, 64, 64);
	if (!anime->move_left)
		return (1);
	anime->move_right = make_right_move_anime(mlx, 64, 64);
	if (!anime->move_right)
		return (1);
	return (0);
}

t_enemy_anime	*make_enemy_anime(void *mlx)
{
	t_enemy_anime	*anime;
	
	anime = malloc(sizeof(t_enemy_anime));
	if (!anime)
		return (NULL);
	anime->idle_left = NULL;
	anime->idle_right = NULL;
	anime->move_right = NULL;
	anime->move_left = NULL;
	if (feel_enemy_anime(mlx, anime) != 0)
		return (free_enemy_anime(anime));
	return (anime);
}

void	*free_enemy_anime(t_enemy_anime *anime)
{
	if (anime->idle_left)
		free_anime(anime->idle_left);
	if (anime->idle_right)
		free_anime(anime->idle_right);
	if (anime->move_right)
		free_anime(anime->move_right);
	if (anime->move_left)
		free_anime(anime->move_left);
	free(anime);
	return (NULL);
}