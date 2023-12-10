/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:44:51 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/11 00:11:29 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_font_print.h"

t_writer	*make_writer(void *mlx, void *win, int space)
{
	t_writer	*writer;

	writer = malloc(sizeof(t_writer));
	if (!writer)
		return (NULL);
	writer->symbols = NULL;
	writer->mlx = mlx;
	writer->win = win;
	writer->space = space;
	return (writer);
}

int	add_symbol(t_writer *writer, char ch, char *image_path)
{
	t_symbol	*last;

	if (!writer)
		return (1);
	last = writer->symbols;
	while (last)
	{
		if (!last->next)
			break ;
		last = last->next;
	}
	if (last)
	{
		last->next = make_symbol(writer->mlx, ch, image_path);
		return (last->next == NULL);
	}
	writer->symbols = make_symbol(writer->mlx, ch, image_path);
	return (writer->symbols == NULL);
}

void	*free_writer(t_writer *writer)
{
	if (!writer)
		return (NULL);
	if (writer->symbols)
		free_symbol(writer->symbols);
	free(writer);
	return (NULL);
}
