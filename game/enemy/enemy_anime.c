/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_anime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:53:39 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 23:11:34 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

static void	init_enemy_anime(t_enemy_anime *anime)
{
	anime->idle_left = NULL;
	anime->move_left = NULL;
	anime->idle_right = NULL;
	anime->move_right = NULL;
	anime->died = NULL;
	anime->die = NULL;
	anime->die_anime_done = 0;
}

static int	feel_enemy_anime(void *mlx, t_enemy_anime *anime)
{
	anime->idle_left = make_left_idle_anime(mlx);
	if (!anime->idle_left)
		return (1);
	anime->idle_right = make_right_idle_anime(mlx);
	if (!anime->idle_right)
		return (1);
	anime->move_left = make_left_move_anime(mlx);
	if (!anime->move_left)
		return (1);
	anime->move_right = make_right_move_anime(mlx);
	if (!anime->move_right)
		return (1);
	anime->die = make_die_anime(mlx);
	if (!anime->die)
		return (1);
	anime->died = make_died_anime(mlx);
	if (!anime->died)
		return (1);
	return (0);
}

t_enemy_anime	*make_enemy_anime(void *mlx)
{
	t_enemy_anime	*anime;

	anime = malloc(sizeof(t_enemy_anime));
	if (!anime)
		return (NULL);
	init_enemy_anime(anime);
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
	if (anime->die)
		free_anime(anime->die);
	if (anime->died)
		free_anime(anime->died);
	free(anime);
	return (NULL);
}
