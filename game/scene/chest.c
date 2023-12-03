/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:44:56 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/03 19:04:40 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	*free_chest(t_chest *chest)
{
	if (!chest)
		return (NULL);
	if (chest->open_anime)
		free_anime(chest->open_anime);
	if (chest->close_anime)
		free_anime(chest->close_anime);
	if (chest->obj)
		free_scene_obj(chest->obj);
	free(chest);
	return (NULL);
}

static void	init_chest(t_chest *chest)
{
	chest->open_anime = NULL;
	chest->close_anime = NULL;
	chest->obj = NULL;
	chest->is_open = 0;
	chest->open_in_proc = 0;
	chest->anime_in_proc = 0;
}

t_chest	*make_chest(void *mlx, unsigned int money, int x, int y)
{
	t_chest	*chest;

	chest = malloc(sizeof(t_chest));
	if (!chest)
		return (chest);
	init_chest(chest);
	chest->x = 64 * x;
	chest->y = 64 * (y + 1);
	chest->open_anime = make_chest_open_anime(mlx, 32, 32);	
	if (!chest->open_anime)
		return (free_chest(chest));
	chest->close_anime = make_chest_close_anime(mlx, 32, 32);	
	if (!chest->close_anime)
		return (free_chest(chest));
	chest->obj = make_scene_obj(OBJ_CHEST, NULL, chest->x, chest->y);
	if (!chest->obj)
		return (free_chest(chest));
	chest->money = money;
	chest->obj->is_render = 0;
	return (chest);
}

void	*render_chest(t_chest *chest)
{
	t_anime_tile	*tile;

	if (!chest->open_anime || !chest->close_anime)
		return (NULL);
	if (!chest->open_in_proc && !chest->is_open)
		return (chest->open_anime->init->image);
	if (!chest->open_in_proc && chest->is_open)
		return (chest->close_anime->init->image);
	if (chest->open_in_proc && chest->is_open)
	{
		tile = get_next_tile(chest->open_anime);
		if (tile == chest->open_anime->init)
		{
			if (chest->anime_in_proc)
			{
				chest->anime_in_proc = 0;
				chest->open_in_proc = 0;
			}
			else
			{	
				chest->anime_in_proc = 1;
			}
		}
		return tile->image;
	}
	if (chest->open_in_proc && !chest->is_open)
	{
		tile = get_next_tile(chest->close_anime);
		if (tile == chest->close_anime->init)
		{
			if (chest->anime_in_proc)
			{
				chest->anime_in_proc = 0;
				chest->open_in_proc = 0;
			}
			else
			{	
				chest->anime_in_proc = 1;
			}
		}
		return tile->image;
	}
	return (NULL);
}

int		toggle_chest(t_chest *chest)
{
	int money;

	if (chest->open_in_proc)
		return (0);
	chest->is_open = !chest->is_open;
	chest->open_in_proc = 1;
	money = chest->money;
	chest->money = 0;
	return (money);
}