/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:37:45 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/11 00:08:42 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../utils/mlx_provider/mlx_provider.h"
# include "../game/game.h"
# include "../game/render/render.h"
# include "../game/player/player.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	setup_hooks(t_game *game);

#endif // MAIN_H