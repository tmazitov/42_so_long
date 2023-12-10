/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:44:53 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/11 03:45:26 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anime.h"

void	*free_anime(t_anime *anime)
{
	t_anime_tile	*tile;
	t_anime_tile	*next;
	int				counter;

	if (!anime)
		return (NULL);
	counter = 0;
	tile = anime->init;
	while (anime->tile_count > counter)
	{
		next = tile->next;
		free_anime_tile(anime->mlx, tile);
		tile = next;
		counter++;
	}
	free(anime);
	return (NULL);
}

int	fill_anime(t_anime *anime, char **tile_paths)
{
	t_anime_tile	*init;
	t_anime_tile	*tile;

	if (!tile_paths)
		return (1);
	init = make_anime_tile(anime, *tile_paths);
	if (!init)
		return (1);
	anime->init = init;
	tile_paths++;
	tile = init;
	while (*tile_paths)
	{
		tile->next = make_anime_tile(anime, *tile_paths);
		if (!tile->next)
			return (1);
		tile->next->prev = tile;
		tile = tile->next;
		tile_paths++;
	}
	tile->next = init;
	init->prev = tile;
	return (0);
}

t_anime	*make_anime(void *mlx, char **tile_paths, int life_time)
{
	t_anime	*anime;
	int		tile_count;

	anime = malloc(sizeof(t_anime));
	if (!anime)
		return (NULL);
	tile_count = 0;
	while (tile_paths[tile_count])
		tile_count++;
	anime->init = NULL;
	anime->mlx = mlx;
	anime->tile_counter = 0;
	anime->tile_count = tile_count;
	anime->tile_life_time = life_time;
	anime->render = NULL;
	if (fill_anime(anime, tile_paths) != 0)
		return (free_anime(anime), NULL);
	anime->render = anime->init;
	return (anime);
}

void	refresh_anime(t_anime *anime)
{
	anime->render = anime->init;
}
