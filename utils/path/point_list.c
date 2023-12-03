/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:07:14 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/28 10:39:48 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "path.h"

t_point_list	*make_point_list()
{
	t_point_list	*list;

	list = malloc(sizeof(t_point_list));
	if (!list)
		return (NULL);
	list->points = NULL;
	return (list);
}

void	*free_point_list(t_point_list *list)
{
	t_point_node	*node;

	node = list->points;
	while (node) {
		free_point_node(node);
		node = node->next;
	}
	free(list);
	return (NULL);
}