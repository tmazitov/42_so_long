/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_die_anime.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:41:50 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:43:43 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static t_anime	*make_palyer_died_anime(void *mlx)
{
	char	*tile_paths[2];

	tile_paths[0] = "textures/player/die/tile056.xpm";
	tile_paths[1] = NULL;
	return (make_anime(mlx, tile_paths, 8));
}

static t_anime	*make_player_die_anime(void *mlx)
{
	char	*tile_paths[4];

	tile_paths[0] = "textures/player/die/tile054.xpm";
	tile_paths[1] = "textures/player/die/tile055.xpm";
	tile_paths[2] = "textures/player/die/tile056.xpm";
	tile_paths[3] = NULL;
	return (make_anime(mlx, tile_paths, 12));
}

int	setup_die_anime(t_player *player, t_player_anime *player_anime)
{
	void	*mlx;

	mlx = player->mlx;
	player_anime->die = make_player_die_anime(mlx);
	if (!player_anime->die)
		return (1);
	player_anime->died = make_palyer_died_anime(mlx);
	if (!player_anime->died)
		return (1);
	return (0);
}
