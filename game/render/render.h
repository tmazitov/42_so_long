/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:52:24 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 14:13:11 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../game.h"

typedef enum s_step{
	TO_NONE		= 0,
	TO_TOP		= 1,
	TO_RIGHT	= 2,
	TO_LEFT		= 3,
	TO_BOT		= 4,
}		t_step;

int		render_hook(t_game *game);

void 	render_player(t_game *game);
void	render_player_road(t_game *game);
void 	render_player_money(t_game *game);
void 	render_player_score(t_game *game);
void 	render_player_health_bar(t_game *game);

void	render_enemy(t_game	*game);
void	render_enemy_health_bar(t_game *game);

void	render_scene(t_game *game);
void	render_scene_objs(t_game *game);
void	render_chests(t_game *game);

void	render_colliders(t_game *game);
void	render_hit_box(t_game *game);

char	*ft_itoa(int n);

#endif // RENDER_H