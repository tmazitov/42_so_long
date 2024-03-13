/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:46:43 by tmazitov          #+#    #+#             */
/*   Updated: 2024/03/13 16:18:03 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	setup_hooks(t_game *game)
{
	mlx_key_hook(game->window, player_control_hook, game);
	mlx_loop_hook(game->mlx, render_hook, game);
	mlx_loop(game->mlx);
}
