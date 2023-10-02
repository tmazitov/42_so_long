/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_attack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:32:43 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/02 18:38:34 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static t_anime	*make_attack_1_anime(void *mlx, int height, int width)
{
	char	*tilePaths[6];

	tilePaths[0] = "textures/player/attack_1/tile000.xpm";
	tilePaths[1] = "textures/player/attack_1/tile001.xpm";
	tilePaths[2] = "textures/player/attack_1/tile002.xpm";
	tilePaths[3] = "textures/player/attack_1/tile003.xpm";
	tilePaths[4] = "textures/player/attack_1/tile004.xpm";
	tilePaths[5] = NULL;
	return make_anime(mlx, tilePaths, height, width, 5);
}
static t_anime	*make_attack_2_anime(void *mlx, int height, int width)
{
	char	*tilePaths[6];

	tilePaths[0] = "textures/player/attack_2/tile000.xpm";
	tilePaths[1] = "textures/player/attack_2/tile001.xpm";
	tilePaths[2] = "textures/player/attack_2/tile002.xpm";
	tilePaths[3] = "textures/player/attack_2/tile003.xpm";
	tilePaths[4] = "textures/player/attack_2/tile004.xpm";
	tilePaths[5] = NULL;
	return make_anime(mlx, tilePaths, height, width, 5);
}
static t_anime	*make_attack_3_anime(void *mlx, int height, int width)
{
	char	*tilePaths[7];

	tilePaths[0] = "textures/player/attack_3/tile000.xpm";
	tilePaths[1] = "textures/player/attack_3/tile001.xpm";
	tilePaths[2] = "textures/player/attack_3/tile002.xpm";
	tilePaths[3] = "textures/player/attack_3/tile003.xpm";
	tilePaths[4] = "textures/player/attack_3/tile004.xpm";
	tilePaths[5] = "textures/player/attack_3/tile005.xpm";
	tilePaths[6] = NULL;
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
	player_anime->attack_1 = make_attack_1_anime(mlx, height, width);
	if (!player_anime->attack_1)
		return (1);
	player_anime->attack_2 = make_attack_2_anime(mlx, height, width);
	if (!player_anime->attack_2)
		return (1);
	player_anime->attack_3 = make_attack_3_anime(mlx, height, width);
	if (!player_anime->attack_3)
		return (1);
	return (0);
}