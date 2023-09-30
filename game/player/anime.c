/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:10:20 by tmazitov          #+#    #+#             */
/*   Updated: 2023/09/30 18:03:45 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	*free_player_anime(t_player_anime *anime)
{
	if (anime->idle)
		free_anime(anime->idle);
	free(anime);
	return (NULL);
}

static t_anime	*make_idle_anime(void *mlx, int height, int width)
{
	char	*tilePaths[10];

	tilePaths[0] = "textures/player/idle/tile000.xpm";
	tilePaths[1] = "textures/player/idle/tile001.xpm";
	tilePaths[2] = "textures/player/idle/tile002.xpm";
	tilePaths[3] = "textures/player/idle/tile003.xpm";
	tilePaths[4] = "textures/player/idle/tile004.xpm";
	tilePaths[5] = "textures/player/idle/tile005.xpm";
	tilePaths[6] = "textures/player/idle/tile006.xpm";
	tilePaths[7] = "textures/player/idle/tile007.xpm";
	tilePaths[8] = "textures/player/idle/tile008.xpm";
	tilePaths[9] = NULL;
	return make_anime(mlx, tilePaths, height, width);
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
	height = player->height;
	width = player->width;
	mlx = player->mlx;
	player_anime->idle = make_idle_anime(mlx, height, width);
	if (!player_anime->idle)
		return (free(player), NULL);
	return (player_anime);
}

