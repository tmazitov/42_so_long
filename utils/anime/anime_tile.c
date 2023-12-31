/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:20:48 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:50:14 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anime.h"

void	*free_anime_tile(void *mlx, t_anime_tile *tile)
{
	if (!tile)
		return (NULL);
	if (tile->image)
		mlx_destroy_image(mlx, tile->image);
	free(tile);
	return (NULL);
}

static void	init_anime_tile(t_anime_tile *tile)
{
	tile->image = NULL;
	tile->next = NULL;
	tile->prev = NULL;
}

t_anime_tile	*make_anime_tile(t_anime *anime, char *path)
{
	t_anime_tile	*tile;
	int				*width;
	int				*height;

	tile = malloc(sizeof(t_anime));
	if (!tile)
		return (NULL);
	init_anime_tile(tile);
	tile->height = 0;
	tile->width = 0;
	width = &tile->width;
	height = &tile->height;
	tile->image = mlx_xpm_file_to_image(anime->mlx, path, width, height);
	if (!tile->image)
		return (free_anime_tile(anime->mlx, tile));
	return (tile);
}

t_anime_tile	*get_next_tile(t_anime *anime)
{
	if (anime->tile_counter > anime->tile_life_time)
	{
		anime->render = anime->render->next;
		anime->tile_counter = 0;
	}
	else
		anime->tile_counter++;
	return (anime->render);
}

t_anime_tile	*get_next_tile_rev(t_anime *anime)
{
	if (anime->tile_counter > anime->tile_life_time)
	{
		anime->render = anime->render->prev;
		anime->tile_counter = 0;
	}
	else
		anime->tile_counter++;
	return (anime->render);
}
