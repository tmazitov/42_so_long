/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:20:48 by tmazitov          #+#    #+#             */
/*   Updated: 2023/09/30 18:57:54 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anime.h"

void	*free_anime_tile(t_anime_tile *tile)
{	
	free(tile->image);
	free(tile);
	return (NULL);
}	

t_anime_tile	*make_anime_tile(t_anime *anime, char *tile_path)
{
	t_anime_tile	*anime_tile;
	int				width;
	int				height;

	anime_tile = malloc(sizeof(t_anime));
	if (!anime_tile)
		return (NULL);
	height = anime->height;
	width = anime->width;
	anime_tile->image = mlx_xpm_file_to_image(anime->mlx, tile_path, &width, &height);
	if (!anime_tile->image)
		return (free_anime_tile(anime_tile));
	anime_tile->next = NULL;
	return (anime_tile);
}

t_anime_tile	*get_next_tile(t_anime *anime)
{
	if (anime->counter > TILE_LIFE_TIME)
	{
		anime->render = anime->render->next;
		anime->counter = 0;
		printf("new anime tile!\n");
	}
	else
		anime->counter++;
	return (anime->render);
}