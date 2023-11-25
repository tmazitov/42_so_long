/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:39:17 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/25 16:05:12 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

t_enemy	*make_enemy()
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy) 
		return (NULL);
	enemy->anime = make_enemy_anime();
	if (!enemy->anime)
		return (free_anime(enemy));
	return (enemy);
}

void	*free_enemy(t_enemy *enemy)
{
	if (enemy->anime)
		free_enemy_anime(enemy->anime);
	free(enemy);
}