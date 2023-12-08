/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_idle_anime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:39:26 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/08 16:33:36 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_anime	*make_idle_down_anime(void *mlx, int height, int width)
{
	char	**tilePaths;
	tilePaths = malloc(sizeof(char*) * 7);
	if (!tilePaths)
		return (NULL);

	tilePaths[0] = "textures/player/idle_down/tile000.xpm";
	tilePaths[1] = "textures/player/idle_down/tile001.xpm";
	tilePaths[2] = "textures/player/idle_down/tile002.xpm";
	tilePaths[3] = "textures/player/idle_down/tile003.xpm";
	tilePaths[4] = "textures/player/idle_down/tile004.xpm";
	tilePaths[5] = "textures/player/idle_down/tile005.xpm";
	tilePaths[6] = NULL;
	return make_anime(mlx, tilePaths, height, width, 6);
}

t_anime	*make_idle_up_anime(void *mlx, int height, int width)
{
	char	**tilePaths;
	tilePaths = malloc(sizeof(char*) * 7);
	if (!tilePaths)
		return (NULL);

	tilePaths[0] = "textures/player/idle_up/tile012.xpm";
	tilePaths[1] = "textures/player/idle_up/tile013.xpm";
	tilePaths[2] = "textures/player/idle_up/tile014.xpm";
	tilePaths[3] = "textures/player/idle_up/tile015.xpm";
	tilePaths[4] = "textures/player/idle_up/tile016.xpm";
	tilePaths[5] = "textures/player/idle_up/tile017.xpm";
	tilePaths[6] = NULL;
	return make_anime(mlx, tilePaths, height, width, 6);
}

t_anime	*make_idle_right_anime(void *mlx, int height, int width)
{
	char	**tilePaths;
	tilePaths = malloc(sizeof(char*) * 7);
	if (!tilePaths)
		return (NULL);

	tilePaths[0] = "textures/player/idle_right/tile006.xpm";
	tilePaths[1] = "textures/player/idle_right/tile007.xpm";
	tilePaths[2] = "textures/player/idle_right/tile008.xpm";
	tilePaths[3] = "textures/player/idle_right/tile009.xpm";
	tilePaths[4] = "textures/player/idle_right/tile010.xpm";
	tilePaths[5] = "textures/player/idle_right/tile011.xpm";
	tilePaths[6] = NULL;
	return make_anime(mlx, tilePaths, height, width, 6);
}

t_anime	*make_idle_left_anime(void *mlx, int height, int width)
{
	char	**tilePaths;
	tilePaths = malloc(sizeof(char*) * 7);
	if (!tilePaths)
		return (NULL);

	tilePaths[0] = "textures/player/idle_left/m_tile006.xpm";
	tilePaths[1] = "textures/player/idle_left/m_tile007.xpm";
	tilePaths[2] = "textures/player/idle_left/m_tile008.xpm";
	tilePaths[3] = "textures/player/idle_left/m_tile009.xpm";
	tilePaths[4] = "textures/player/idle_left/m_tile010.xpm";
	tilePaths[5] = "textures/player/idle_left/m_tile011.xpm";
	tilePaths[6] = NULL;
	return make_anime(mlx, tilePaths, height, width, 6);
}

int	setup_idle_anime(t_player *player, t_player_anime *player_anime)
{
	void	*mlx;
	int		height;
	int		width;
	
	height = player->height;
	width = player->width;
	mlx = player->mlx;
	player_anime->idle_down = make_idle_down_anime(mlx, height, width);
	if (!player_anime->idle_down)
		return (1);
	player_anime->idle_up = make_idle_up_anime(mlx, height, width);
	if (!player_anime->idle_up)
		return (1);
	player_anime->idle_right = make_idle_right_anime(mlx, height, width);
	if (!player_anime->idle_right)
		return (1);
	player_anime->idle_left = make_idle_left_anime(mlx, height, width);
	if (!player_anime->idle_left)
		return (1);
	return (0);
}