/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_anime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:53:39 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/25 16:02:05 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

static int	feel_enemy_anime(t_enemy_anime *anime)
{
	
}

t_enemy_anime	*make_enemy_anime()
{
	t_enemy_anime	*anime;
	
	anime = malloc(sizeof(t_enemy_anime));
	if (!anime)
		return (NULL);
	if (feel_enemy_anime(anime) != 0)
		return (free_enemy_anime(anime));
	return (anime);
}

void	*free_enemy_anime(t_enemy_anime *anime)
{
	free(anime);
}