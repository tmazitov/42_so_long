/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:10:20 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/09 08:54:18 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	*free_player_anime(t_player_anime *anime)
{
	if (anime->idle_down)
		free_anime(anime->idle_down);
	if (anime->idle_up)
		free_anime(anime->idle_up);
	if (anime->idle_right)
		free_anime(anime->idle_right);
	if (anime->walk_left)
		free_anime(anime->walk_left);
	if (anime->walk_right)
		free_anime(anime->walk_right);
	if (anime->attack_up)
		free_anime(anime->attack_up);
	if (anime->attack_down)
		free_anime(anime->attack_down);
	if (anime->attack_right)
		free_anime(anime->attack_right);
	if (anime->attack_left)
		free_anime(anime->attack_left);
	free(anime);
	return (NULL);
}

static t_anime	*make_idle_down_anime(void *mlx, int height, int width)
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
	return make_anime(mlx, tilePaths, height, width, 9);
}
static t_anime	*make_idle_up_anime(void *mlx, int height, int width)
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
	return make_anime(mlx, tilePaths, height, width, 9);
}
static t_anime	*make_idle_right_anime(void *mlx, int height, int width)
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
	return make_anime(mlx, tilePaths, height, width, 9);
}

static t_anime	*make_idle_left_anime(void *mlx, int height, int width)
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
	return make_anime(mlx, tilePaths, height, width, 9);
}

static t_anime	*make_walk_right_anime(void *mlx, int height, int width)
{
	char	**tilePaths;
	tilePaths = malloc(sizeof(char*) * 7);
	if (!tilePaths)
		return (NULL);

	tilePaths[0] = "textures/player/walk_right/tile024.xpm";
	tilePaths[1] = "textures/player/walk_right/tile025.xpm";
	tilePaths[2] = "textures/player/walk_right/tile026.xpm";
	tilePaths[3] = "textures/player/walk_right/tile027.xpm";
	tilePaths[4] = "textures/player/walk_right/tile028.xpm";
	tilePaths[5] = "textures/player/walk_right/tile029.xpm";
	tilePaths[6] = NULL;
	return make_anime(mlx, tilePaths, height, width, 6);
}

static t_anime	*make_walk_left_anime(void *mlx, int height, int width)
{
	char	**tilePaths;
	tilePaths = malloc(sizeof(char*) * 7);
	if (!tilePaths)
		return (NULL);

	tilePaths[0] = "textures/player/walk_left/m_tile024.xpm";
	tilePaths[1] = "textures/player/walk_left/m_tile025.xpm";
	tilePaths[2] = "textures/player/walk_left/m_tile026.xpm";
	tilePaths[3] = "textures/player/walk_left/m_tile027.xpm";
	tilePaths[4] = "textures/player/walk_left/m_tile028.xpm";
	tilePaths[5] = "textures/player/walk_left/m_tile029.xpm";
	tilePaths[6] = NULL;
	return make_anime(mlx, tilePaths, height, width, 6);
}
static t_anime	*make_walk_down_anime(void *mlx, int height, int width)
{
	char	**tilePaths;
	tilePaths = malloc(sizeof(char*) * 7);
	if (!tilePaths)
		return (NULL);

	tilePaths[0] = "textures/player/walk_down/tile019.xpm";
	tilePaths[1] = "textures/player/walk_down/tile019.xpm";
	tilePaths[2] = "textures/player/walk_down/tile020.xpm";
	tilePaths[3] = "textures/player/walk_down/tile021.xpm";
	tilePaths[4] = "textures/player/walk_down/tile022.xpm";
	tilePaths[5] = "textures/player/walk_down/tile023.xpm";
	tilePaths[6] = NULL;
	return make_anime(mlx, tilePaths, height, width, 6);
}
static t_anime	*make_walk_up_anime(void *mlx, int height, int width)
{
	char	**tilePaths;
	tilePaths = malloc(sizeof(char*) * 6);
	if (!tilePaths)
		return (NULL);

	tilePaths[0] = "textures/player/walk_up/tile030.xpm";
	tilePaths[1] = "textures/player/walk_up/tile031.xpm";
	tilePaths[2] = "textures/player/walk_up/tile033.xpm";
	tilePaths[3] = "textures/player/walk_up/tile034.xpm";
	tilePaths[4] = "textures/player/walk_up/tile035.xpm";
	tilePaths[5] = NULL;
	return make_anime(mlx, tilePaths, height, width, 6);
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

	// IDLE

	player_anime->idle_down = make_idle_down_anime(mlx, height, width);
	if (!player_anime->idle_down)
		return (NULL);
	player_anime->idle_up = make_idle_up_anime(mlx, height, width);
	if (!player_anime->idle_up)
		return (NULL);
	player_anime->idle_right = make_idle_right_anime(mlx, height, width);
	if (!player_anime->idle_right)
		return (NULL);
	player_anime->idle_left = make_idle_left_anime(mlx, height, width);
	if (!player_anime->idle_left)
		return (NULL);

	// WALK

	player_anime->walk_down = make_walk_down_anime(mlx, height, width);
	if (!player_anime->walk_down)
		return (NULL);
	
	player_anime->walk_up = make_walk_up_anime(mlx, height, width);
	if (!player_anime->walk_up)
		return (NULL);

	player_anime->walk_right = make_walk_right_anime(mlx, height, width);
	if (!player_anime->walk_right)
		return (NULL);
	
	player_anime->walk_left = make_walk_left_anime(mlx, height, width);
	if (!player_anime->walk_left)
		return (NULL);

	if (setup_attack_anime(player, player_anime) != 0)
		return (NULL);
	return (player_anime);
}

