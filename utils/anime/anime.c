/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:44:53 by tmazitov          #+#    #+#             */
/*   Updated: 2023/09/30 18:43:34 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anime.h"

void	*free_anime(t_anime *anime)
{
	t_anime_tile *tile;
	t_anime_tile *next;

	tile = anime->top;
	while(tile)
	{
		next = tile->next;
		free_anime_tile(tile);
		tile = next;
	}
	free(anime);
	return (NULL);
}

int	fill_anime(t_anime *anime, char **tile_paths)
{
	t_anime_tile	*init;
	t_anime_tile	*tile;
	
	if (!tile_paths)
		return 1;
	init = make_anime_tile(anime, *tile_paths);
	if (!init)
		return (1);
	printf("anime tile loaded: %s\n", *tile_paths);
	tile_paths++;
	tile = init;
	while (*tile_paths)
	{
		tile->next = make_anime_tile(anime, *tile_paths);
		if (!tile->next)
			return (1);
		printf("anime tile loaded: %s\n", *tile_paths);
		tile = tile->next;
		tile_paths++;
	}
	if (tile != init)
		tile->next = init;
	anime->top = init;
	return (0);
}

t_anime *make_anime(void *mlx, char **tile_paths, int height, int width)
{
	t_anime	*anime;
	int		tile_count;
	
	anime = malloc(sizeof(t_anime));
	if (!anime)
		return (NULL);
	tile_count = 0;
	while(tile_paths[tile_count++])
	anime->top = NULL;
	anime->height = height;
	anime->width = width;
	anime->mlx = mlx;
	anime->counter = 0;
	if (fill_anime(anime, tile_paths) != 0)
		return (free(anime), NULL);
	anime->render = anime->top;
	return (anime);
}