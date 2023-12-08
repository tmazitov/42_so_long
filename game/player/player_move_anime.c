/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_anime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:21:16 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/08 16:26:16 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static t_anime	*make_walk_right_anime(void *mlx, int height, int width)
{
	char	*tilePaths[7];

	tilePaths[0] = "textures/player/walk_right/tile024.xpm";
	tilePaths[1] = "textures/player/walk_right/tile025.xpm";
	tilePaths[2] = "textures/player/walk_right/tile026.xpm";
	tilePaths[3] = "textures/player/walk_right/tile027.xpm";
	tilePaths[4] = "textures/player/walk_right/tile028.xpm";
	tilePaths[5] = "textures/player/walk_right/tile029.xpm";
	tilePaths[6] = NULL;
	return make_anime(mlx, tilePaths, height, width, 3);
}

static t_anime	*make_walk_left_anime(void *mlx, int height, int width)
{
	char	*tilePaths[7];

	tilePaths[0] = "textures/player/walk_left/m_tile024.xpm";
	tilePaths[1] = "textures/player/walk_left/m_tile025.xpm";
	tilePaths[2] = "textures/player/walk_left/m_tile026.xpm";
	tilePaths[3] = "textures/player/walk_left/m_tile027.xpm";
	tilePaths[4] = "textures/player/walk_left/m_tile028.xpm";
	tilePaths[5] = "textures/player/walk_left/m_tile029.xpm";
	tilePaths[6] = NULL;
	return make_anime(mlx, tilePaths, height, width, 3);
}
static t_anime	*make_walk_down_anime(void *mlx, int height, int width)
{
	char	*tilePaths[7];
	
	tilePaths[0] = "textures/player/walk_down/tile019.xpm";
	tilePaths[1] = "textures/player/walk_down/tile019.xpm";
	tilePaths[2] = "textures/player/walk_down/tile020.xpm";
	tilePaths[3] = "textures/player/walk_down/tile021.xpm";
	tilePaths[4] = "textures/player/walk_down/tile022.xpm";
	tilePaths[5] = "textures/player/walk_down/tile023.xpm";
	tilePaths[6] = NULL;
	return make_anime(mlx, tilePaths, height, width, 3);
}
static t_anime	*make_walk_up_anime(void *mlx, int height, int width)
{
	char	*tilePaths[7];

	tilePaths[0] = "textures/player/walk_up/tile030.xpm";
	tilePaths[1] = "textures/player/walk_up/tile031.xpm";
	tilePaths[2] = "textures/player/walk_up/tile033.xpm";
	tilePaths[3] = "textures/player/walk_up/tile034.xpm";
	tilePaths[4] = "textures/player/walk_up/tile035.xpm";
	tilePaths[5] = NULL;
	return make_anime(mlx, tilePaths, height, width, 3);
}

int	setup_move_anime(t_player *player, t_player_anime *player_anime)
{
	void	*mlx;
	int		height;
	int		width;
	
	height = player->height;
	width = player->width;
	mlx = player->mlx;
	player_anime->walk_down = make_walk_down_anime(mlx, height, width);
	if (!player_anime->walk_down)
		return (1);
	player_anime->walk_up = make_walk_up_anime(mlx, height, width);
	if (!player_anime->walk_up)
		return (1);
	player_anime->walk_right = make_walk_right_anime(mlx, height, width);
	if (!player_anime->walk_right)
		return (1);
	player_anime->walk_left = make_walk_left_anime(mlx, height, width);
	if (!player_anime->walk_left)
		return (1);
	return (0);
}