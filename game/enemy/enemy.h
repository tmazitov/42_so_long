/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:39:24 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/25 16:03:31 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMY_H
# define ENUMY_H

#include <stdlib.h>
#include "../../utils/collider/collider.h"
#include "../../utils/anime/anime.h"

typedef	struct s_enemy_anime
{
	t_anime	*idle;
}		t_enemy_anime;


typedef struct s_enemy
{
	int				health;
	t_collider		*coll;
	t_enemy_anime	*anime;
}		t_enemy;

t_enemy	*make_enemy();
void	*free_enemy(t_enemy *enemy);

t_enemy_anime	*make_enemy_anime();
void			*free_enemy_anime();
#endif 