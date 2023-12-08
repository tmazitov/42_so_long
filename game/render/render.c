/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:51:46 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/08 15:43:01 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	render_hook(t_game *game)
{
	if (game->blocker)
	{
		return (1);
	}
	
	mlx_clear_window(game->mlx, game->window);
	render_scene(game);
	render_chests(game);
	render_player(game);
	render_enemy(game);
	render_scene_objs(game);
	render_enemy_health_bar(game);
	render_player_health_bar(game);
	// render_colliders(game);
	// render_hit_box(game);
	render_player_money(game);
	mlx_do_sync(game->mlx);
	return (0);
}
