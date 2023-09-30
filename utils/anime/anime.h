/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:45:01 by tmazitov          #+#    #+#             */
/*   Updated: 2023/09/30 22:39:14 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIME_H
# define ANIME_H

# include "../../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct s_anime_tile
{
	void				*image;
	struct s_anime_tile	*next;
}		t_anime_tile;

typedef struct s_anime
{
	void			*mlx;
	int				tile_count;
	int				tile_counter;
	int				tile_life_time;
	int				height;
	int				width;
	t_anime_tile	*render;
	t_anime_tile	*init;
}		t_anime;

t_anime			*make_anime(void *mlx, char **tile_paths, int height, int width, int life_time);
int				fill_anime(t_anime *anime, char **tilePaths);
void			*free_anime(t_anime *anime);
void			refresh_anime(t_anime *anime);

t_anime_tile	*get_next_tile(t_anime *anime);
t_anime_tile	*make_anime_tile(t_anime *anime, char *tilePath);
void			*free_anime_tile(t_anime_tile *tile);

#endif