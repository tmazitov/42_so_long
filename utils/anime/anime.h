/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:45:01 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:48:46 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIME_H
# define ANIME_H

# include "../../mlx/mlx.h"
# include "../printf/ft_printf.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_anime_tile
{
	void				*image;
	int					height;
	int					width;
	struct s_anime_tile	*next;
	struct s_anime_tile	*prev;
}						t_anime_tile;

typedef struct s_anime
{
	void			*mlx;
	int				tile_count;
	int				tile_counter;
	int				tile_life_time;
	t_anime_tile	*render;
	t_anime_tile	*init;
}					t_anime;

t_anime				*make_anime(void *mlx, char **tile_paths, int life_time);
int					fill_anime(t_anime *anime, char **tilePaths);
void				*free_anime(t_anime *anime);
void				refresh_anime(t_anime *anime);

t_anime_tile		*get_next_tile(t_anime *anime);
t_anime_tile		*get_next_tile_rev(t_anime *anime);
t_anime_tile		*make_anime_tile(t_anime *anime, char *tilePath);
void				*free_anime_tile(void *mlx, t_anime_tile *tile);
#endif