/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:03:06 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:22:40 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_raw_node	*make_node(char *data)
{
	t_raw_node	*raw_node;

	if (!data)
		return (NULL);
	raw_node = malloc(sizeof(t_raw_node));
	if (!raw_node)
		return (NULL);
	raw_node->data = data;
	raw_node->next = NULL;
	return (raw_node);
}

void	*free_node(t_raw_node *node)
{
	if (!node)
		return (NULL);
	if (node->next)
		free_node(node->next);
	if (node->data)
		free(node->data);
	free(node);
	return (NULL);
}
