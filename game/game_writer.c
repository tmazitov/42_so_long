/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_writer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:57:08 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/09 15:12:37 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	feed_game_writer_digits(t_writer *writer)
{
	int res;

	res += add_symbol(writer, '0', "textures/font/0.xpm");
	res += add_symbol(writer, '1', "textures/font/1.xpm");
	res += add_symbol(writer, '2', "textures/font/2.xpm");
	res += add_symbol(writer, '3', "textures/font/3.xpm");
	res += add_symbol(writer, '4', "textures/font/4.xpm");
	res += add_symbol(writer, '5', "textures/font/5.xpm");
	res += add_symbol(writer, '6', "textures/font/6.xpm");
	res += add_symbol(writer, '7', "textures/font/7.xpm");
	res += add_symbol(writer, '8', "textures/font/8.xpm");
	res += add_symbol(writer, '9', "textures/font/9.xpm");
	return (res);
}
static int	feed_game_writer_letters(t_writer *writer)
{
	int res;

	res += add_symbol(writer, 'A', "textures/font/a.xpm");
	res += add_symbol(writer, 'B', "textures/font/b.xpm");
	res += add_symbol(writer, 'C', "textures/font/c.xpm");
	res += add_symbol(writer, 'D', "textures/font/d.xpm");
	res += add_symbol(writer, 'E', "textures/font/e.xpm");
	res += add_symbol(writer, 'F', "textures/font/f.xpm");
	res += add_symbol(writer, 'J', "textures/font/j.xpm");
	res += add_symbol(writer, 'H', "textures/font/h.xpm");
	res += add_symbol(writer, 'I', "textures/font/i.xpm");
	res += add_symbol(writer, 'J', "textures/font/j.xpm");
	res += add_symbol(writer, 'K', "textures/font/k.xpm");
	res += add_symbol(writer, 'L', "textures/font/l.xpm");
	res += add_symbol(writer, 'M', "textures/font/m.xpm");
	res += add_symbol(writer, 'N', "textures/font/n.xpm");
	res += add_symbol(writer, 'O', "textures/font/o.xpm");
	res += add_symbol(writer, 'P', "textures/font/p.xpm");
	res += add_symbol(writer, 'Q', "textures/font/q.xpm");
	res += add_symbol(writer, 'R', "textures/font/r.xpm");
	res += add_symbol(writer, 'S', "textures/font/s.xpm");
	res += add_symbol(writer, 'T', "textures/font/t.xpm");
	res += add_symbol(writer, 'U', "textures/font/u.xpm");
	res += add_symbol(writer, 'V', "textures/font/v.xpm");
	res += add_symbol(writer, 'W', "textures/font/w.xpm");
	res += add_symbol(writer, 'X', "textures/font/x.xpm");
	res += add_symbol(writer, 'Y', "textures/font/y.xpm");
	res += add_symbol(writer, 'Z', "textures/font/z.xpm");
	return (res);
}

int	feed_game_writer(t_writer *writer)
{
	if (!writer)
		return (1);
	if (feed_game_writer_digits(writer))
		return (1);
	return feed_game_writer_letters(writer);
}