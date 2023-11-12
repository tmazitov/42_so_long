/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:44:56 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/09 13:33:58 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	*free_chest(t_chest *chest)
{
	free(chest);
	return (NULL);
}

t_chest	*make_chest(unsigned int money, t_anime *open, t_anime *close, int x, int y)
{
	t_chest	*chest;

	if (!open || !close)
		return (NULL);
	chest = malloc(sizeof(t_chest *));
	if (!chest)
		return (chest);
	chest->obj = make_scene_obj(OBJ_CHEST,open->init->image, x, y);
	if (!chest->obj)
		return (free_chest(chest));
	chest->open_anime = open;
	chest->close_anime = close;
	chest->is_open = 0;
	chest->open_in_proc = 0;
	chest->anime_in_proc = 0;
	chest->money = money;
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