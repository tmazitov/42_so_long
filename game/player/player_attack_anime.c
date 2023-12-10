/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_attack_anime.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:32:43 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:43:51 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static t_anime	*make_attack_up_anime(void *mlx)
{
	char	*tile_paths[5];

	tile_paths[0] = "textures/player/attack-up/tile048.xpm";
	tile_paths[1] = "textures/player/attack-up/tile049.xpm";
	tile_paths[2] = "textures/player/attack-up/tile050.xpm";
	tile_paths[3] = "textures/player/attack-up/tile051.xpm";
	tile_paths[4] = NULL;
	return (make_anime(mlx, tile_paths, 2));
}

static t_anime	*make_attack_down_anime(void *mlx)
{
	char	*tile_paths[5];

	tile_paths[0] = "textures/player/attack-down/tile036.xpm";
	tile_paths[1] = "textures/player/attack-down/tile037.xpm";
	tile_paths[2] = "textures/player/attack-down/tile038.xpm";
	tile_paths[3] = "textures/player/attack-down/tile039.xpm";
	tile_paths[4] = NULL;
	return (make_anime(mlx, tile_paths, 2));
}

static t_anime	*make_attack_left_anime(void *mlx)
{
	char	*tile_paths[5];

	tile_paths[0] = "textures/player/attack-left/m_tile042.xpm";
	tile_paths[1] = "textures/player/attack-left/m_tile043.xpm";
	tile_paths[2] = "textures/player/attack-left/m_tile044.xpm";
	tile_paths[3] = "textures/player/attack-left/m_tile045.xpm";
	tile_paths[4] = NULL;
	return (make_anime(mlx, tile_paths, 2));
}

static t_anime	*make_attack_right_anime(void *mlx)
{
	char	*tile_paths[5];

	tile_paths[0] = "textures/player/attack-right/tile042.xpm";
	tile_paths[1] = "textures/player/attack-right/tile043.xpm";
	tile_paths[2] = "textures/player/attack-right/tile044.xpm";
	tile_paths[3] = "textures/player/attack-right/tile045.xpm";
	tile_paths[4] = NULL;
	return (make_anime(mlx, tile_paths, 2));
}

int	setup_attack_anime(t_player *player, t_player_anime *player_anime)
{
	void	*mlx;

	mlx = player->mlx;
	player_anime->attack_up = make_attack_up_anime(mlx);
	if (!player_anime->attack_up)
		return (1);
	player_anime->attack_down = make_attack_down_anime(mlx);
	if (!player_anime->attack_down)
		return (1);
	player_anime->attack_right = make_attack_right_anime(mlx);
	if (!player_anime->attack_right)
		return (1);
	player_anime->attack_left = make_attack_left_anime(mlx);
	if (!player_anime->attack_right)
		return (1);
	return (0);
}
