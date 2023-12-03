/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:51:46 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/03 15:08:42 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"



int	render_hook(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	render_scene(game);
	render_chests(game);
	render_enemy(game);
	render_player(game);
	render_scene_objs(game);
	render_player_health_bar(game);
	render_enemy_health_bar(game);
	// render_colliders(game);
	// render_hit_box(game);
	return (0);
}
