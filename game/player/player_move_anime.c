/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_anime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:21:16 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:44:56 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static t_anime	*make_walk_right_anime(void *mlx)
{
	char	*tile_paths[7];

	tile_paths[0] = "textures/player/walk_right/tile024.xpm";
	tile_paths[1] = "textures/player/walk_right/tile025.xpm";
	tile_paths[2] = "textures/player/walk_right/tile026.xpm";
	tile_paths[3] = "textures/player/walk_right/tile027.xpm";
	tile_paths[4] = "textures/player/walk_right/tile028.xpm";
	tile_paths[5] = "textures/player/walk_right/tile029.xpm";
	tile_paths[6] = NULL;
	return (make_anime(mlx, tile_paths, 3));
}

static t_anime	*make_walk_left_anime(void *mlx)
{
	char	*tile_paths[7];

	tile_paths[0] = "textures/player/walk_left/m_tile024.xpm";
	tile_paths[1] = "textures/player/walk_left/m_tile025.xpm";
	tile_paths[2] = "textures/player/walk_left/m_tile026.xpm";
	tile_paths[3] = "textures/player/walk_left/m_tile027.xpm";
	tile_paths[4] = "textures/player/walk_left/m_tile028.xpm";
	tile_paths[5] = "textures/player/walk_left/m_tile029.xpm";
	tile_paths[6] = NULL;
	return (make_anime(mlx, tile_paths, 3));
}

static t_anime	*make_walk_down_anime(void *mlx)
{
	char	*tile_paths[7];

	tile_paths[0] = "textures/player/walk_down/tile019.xpm";
	tile_paths[1] = "textures/player/walk_down/tile019.xpm";
	tile_paths[2] = "textures/player/walk_down/tile020.xpm";
	tile_paths[3] = "textures/player/walk_down/tile021.xpm";
	tile_paths[4] = "textures/player/walk_down/tile022.xpm";
	tile_paths[5] = "textures/player/walk_down/tile023.xpm";
	tile_paths[6] = NULL;
	return (make_anime(mlx, tile_paths, 3));
}

static t_anime	*make_walk_up_anime(void *mlx)
{
	char	*tile_paths[7];

	tile_paths[0] = "textures/player/walk_up/tile030.xpm";
	tile_paths[1] = "textures/player/walk_up/tile031.xpm";
	tile_paths[2] = "textures/player/walk_up/tile033.xpm";
	tile_paths[3] = "textures/player/walk_up/tile034.xpm";
	tile_paths[4] = "textures/player/walk_up/tile035.xpm";
	tile_paths[5] = NULL;
	return (make_anime(mlx, tile_paths, 3));
}

int	setup_move_anime(t_player *player, t_player_anime *player_anime)
{
	void	*mlx;

	mlx = player->mlx;
	player_anime->walk_down = make_walk_down_anime(mlx);
	if (!player_anime->walk_down)
		return (1);
	player_anime->walk_up = make_walk_up_anime(mlx);
	if (!player_anime->walk_up)
		return (1);
	player_anime->walk_right = make_walk_right_anime(mlx);
	if (!player_anime->walk_right)
		return (1);
	player_anime->walk_left = make_walk_left_anime(mlx);
	if (!player_anime->walk_left)
		return (1);
	return (0);
}
