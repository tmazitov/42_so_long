/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_font_print.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:39:51 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/09 15:52:16 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MLX_FONT_PRINT_H
# define MLX_FONT_PRINT_H

#include "../image/image.h"
#include "../printf/ft_printf.h"

typedef struct s_symbol
{
	char			symbol;
	t_image			*image;
	struct s_symbol	*next;
}		t_symbol;


typedef struct s_writer
{
	t_symbol	*symbols;
	void		*mlx;
	void		*win;
	int			space;
}		t_writer;

t_symbol	*make_symbol(void *mlx, char ch, char *image_path);
void		*free_symbol(t_symbol *symbol);

t_writer	*make_writer(void *mlx, void *win, int space);
void		*free_writer(t_writer *writer);
int			add_symbol(t_writer *writer, char ch, char *image_path);
int			mlx_print_char(t_writer *w, char ch, int x, int y);
int			mlx_print(t_writer *w, char *str, int x, int y);


#endif