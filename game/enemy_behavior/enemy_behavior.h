/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_behavior.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:54:13 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 23:08:17 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_BEHAVIOR_H
# define ENEMY_BEHAVIOR_H

# include "../player/player.h"
# include "../scene/scene.h"
# include "../enemy/enemy.h"

t_anime	*enemy_handle_move(t_player *player, t_scene *scene, t_enemy *enemy);
t_anime	*exec_enemy_behavior(t_player *player, t_scene *scene, t_enemy *enemy);
void	enemy_handle_attack(t_enemy *enemy, t_player *player);
int		enemy_is_able_to_move(t_enemy *enemy, t_scene *scene, t_player *player);

#endif // !ENEMY_BEHAVIOR_H