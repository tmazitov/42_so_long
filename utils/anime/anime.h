/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:45:01 by tmazitov          #+#    #+#             */
/*   Updated: 2023/09/30 19:00:19 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIME_H
# define ANIME_H

# include "../../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define TILE_LIFE_TIME 15

typedef struct s_anime_tile
{
	void				*image;
	struct s_anime_tile	*next;
}		t_anime_tile;

typedef struct s_anime
{
	void			*mlx;
	int				counter;
	int				height;
	int				width;
	t_anime_tile	*render;
	t_anime_tile	*top;
}		t_anime;

t_anime 		*make_anime(void *mlx, char **tilePaths, int height, int width);
int				fill_anime(t_anime *anime, char **tilePaths);
void			*free_anime(t_anime *anime);

t_anime_tile	*get_next_tile(t_anime *anime);
t_anime_tile	*make_anime_tile(t_anime *anime, char *tilePath);
void			*free_anime_tile(t_anime_tile *tile);

#endif