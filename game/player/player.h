/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:07:26 by tmazitov          #+#    #+#             */
/*   Updated: 2023/09/30 16:33:32 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include <stdlib.h>
# include "../../mlx/mlx.h"
# include "../../utils/anime/anime.h"

typedef struct s_player_anime
{
	t_anime		*idle;
}		t_player_anime;

typedef struct s_player
{
	void				*mlx;
	int					x;
	int					y;
	int					width;
	int					height;
	t_player_anime	*anime;
}		t_player;

t_player		*make_player(void *mlx, int height, int width);
void			*free_player(t_player *player);
t_player_anime	*make_player_anime(t_player *player);
void			*free_player_anime(t_player_anime *anime);

#endif // !PLAYER_H