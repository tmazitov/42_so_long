/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_attack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:32:43 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/09 11:21:12 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static t_anime	*make_attack_up_anime(void *mlx, int height, int width)
{
	char	*tilePaths[5];

	tilePaths[0] = "textures/player/attack-up/tile048.xpm";
	tilePaths[1] = "textures/player/attack-up/tile049.xpm";
	tilePaths[2] = "textures/player/attack-up/tile050.xpm";
	tilePaths[3] = "textures/player/attack-up/tile051.xpm";
	tilePaths[4] = NULL;
	return make_anime(mlx, tilePaths, height, width, 5);
}
static t_anime	*make_attack_down_anime(void *mlx, int height, int width)
{
	char	*tilePaths[5];

	tilePaths[0] = "textures/player/attack-down/tile036.xpm";
	tilePaths[1] = "textures/player/attack-down/tile037.xpm";
	tilePaths[2] = "textures/player/attack-down/tile038.xpm";
	tilePaths[3] = "textures/player/attack-down/tile039.xpm";
	tilePaths[4] = NULL;
	return make_anime(mlx, tilePaths, height, width, 5);
}
static t_anime	*make_attack_left_anime(void *mlx, int height, int width)
{
	char	*tilePaths[5];

	tilePaths[0] = "textures/player/attack-left/m_tile042.xpm";
	tilePaths[1] = "textures/player/attack-left/m_tile043.xpm";
	tilePaths[2] = "textures/player/attack-left/m_tile044.xpm";
	tilePaths[3] = "textures/player/attack-left/m_tile045.xpm";
	tilePaths[4] = NULL;
	return make_anime(mlx, tilePaths, height, width, 5);
}
static t_anime	*make_attack_right_anime(void *mlx, int height, int width)
{
	char	*tilePaths[5];

	tilePaths[0] = "textures/player/attack-right/tile042.xpm";
	tilePaths[1] = "textures/player/attack-right/tile043.xpm";
	tilePaths[2] = "textures/player/attack-right/tile044.xpm";
	tilePaths[3] = "textures/player/attack-right/tile045.xpm";
	tilePaths[4] = NULL;
	return make_anime(mlx, tilePaths, height, width, 5);
}

int	setup_attack_anime(t_player *player, t_player_anime *player_anime)
{
	void	*mlx;
	int		height;
	int		width;
	
	height = player->height;
	width = player->width;
	mlx = player->mlx;
	player_anime->attack_up = make_attack_up_anime(mlx, height, width);
	if (!player_anime->attack_up)
		return (1);
	player_anime->attack_down = make_attack_down_anime(mlx, height, width);
	if (!player_anime->attack_down)
		return (1);
	player_anime->attack_right = make_attack_right_anime(mlx, height, width);
	if (!player_anime->attack_right)
		return (1);
	player_anime->attack_left = make_attack_left_anime(mlx, height, width);
	if (!player_anime->attack_right)
		return (1);
	return (0);
}