/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chest_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:17:27 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 23:21:14 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	*handle_open(t_chest *chest)
{
	t_anime_tile	*tile;

	tile = get_next_tile(chest->open_anime);
	if (tile == chest->open_anime->init)
	{
		if (chest->anime_in_proc)
		{
			chest->anime_in_proc = 0;
			chest->open_in_proc = 0;
		}
		else
			chest->anime_in_proc = 1;
	}
	return (tile->image);
}

static void	*handle_close(t_chest *chest)
{
	t_anime_tile	*tile;

	tile = get_next_tile(chest->open_anime);
	if (tile == chest->open_anime->init)
	{
		if (chest->anime_in_proc)
		{
			chest->anime_in_proc = 0;
			chest->open_in_proc = 0;
		}
		else
			chest->anime_in_proc = 1;
	}
	return (tile->image);
}

void	*render_chest(t_chest *chest)
{
	if (!chest->open_anime || !chest->close_anime)
		return (NULL);
	if (!chest->open_in_proc && !chest->is_open)
		return (chest->open_anime->init->image);
	if (!chest->open_in_proc && chest->is_open)
		return (chest->close_anime->init->image);
	if (chest->open_in_proc && chest->is_open)
		return (handle_open(chest));
	if (chest->open_in_proc && !chest->is_open)
		return (handle_close(chest));
	return (NULL);
}

int	toggle_chest(t_chest *chest)
{
	int	money;

	if (chest->open_in_proc)
		return (0);
	chest->is_open = !chest->is_open;
	chest->open_in_proc = 1;
	money = chest->money;
	chest->money = 0;
	return (money);
}
