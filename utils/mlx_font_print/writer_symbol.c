/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_symbol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:48:28 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/09 14:48:38 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_font_print.h"

t_symbol	*make_symbol(void *mlx, char ch, char *image_path)
{
	t_symbol	*symbol;

	symbol = malloc(sizeof(t_symbol));
	if (!symbol)
		return (NULL);
	symbol->symbol = ch;
	symbol->image = make_image_v2(mlx, image_path);
	if (!symbol->image)
		return (NULL);
	symbol->next = NULL;
	return (symbol);
}

void	*free_symbol(t_symbol *symbol)
{
	if (!symbol)
		return (NULL);
	if (symbol->next)
		free_symbol(symbol->next);
	if (symbol->image)
		free_image(symbol->image);
	free(symbol);
	return (NULL);
}