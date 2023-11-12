/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chest_anime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:20:25 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/09 12:58:40 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_anime	*make_chest_open_anime(void *mlx, int height, int width)
{
	char	**tilePaths;
	tilePaths = malloc(sizeof(char *) * 5);
	if (!tilePaths)
		return (NULL);	
	tilePaths[0] = "textures/chest/chest_1.xpm";
	tilePaths[1] = "textures/chest/chest_2.xpm";
	tilePaths[2] = "textures/chest/chest_3.xpm";
	tilePaths[3] = "textures/chest/chest_4.xpm";
	tilePaths[4] = NULL;
	return make_anime(mlx, tilePaths, height, width, 5);
}

t_anime	*make_chest_close_anime(void *mlx, int height, int width)
{
	char	**tilePaths;
	tilePaths = malloc(sizeof(char *) * 5);
	if (!tilePaths)
		return (NULL);
	tilePaths[0] = "textures/chest/chest_4.xpm";
	tilePaths[1] = "textures/chest/chest_3.xpm";
	tilePaths[2] = "textures/chest/chest_2.xpm";
	tilePaths[3] = "textures/chest/chest_1.xpm";
	tilePaths[4] = NULL;
	return make_anime(mlx, tilePaths, height, width, 5);
}