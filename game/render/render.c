/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:51:46 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/11 02:38:37 by tmazitov         ###   ########.fr       */
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
	render_player_road(game);
	render_exit(game);
	render_chests(game);
	render_enemy(game);
	render_player(game);
	render_scene_objs(game);
	render_enemy_health_bar(game);
	render_player_health_bar(game);
	render_player_money(game);
	render_player_score(game);
	mlx_do_sync(game->mlx);
	return (0);
}
