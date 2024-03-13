/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:07:14 by tmazitov          #+#    #+#             */
/*   Updated: 2024/03/13 12:32:13 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"
#include <stdio.h>

t_point_list	*make_point_list(void)
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
	while (node)
	{
		free_point_node(node);
		node = node->next;
	}
	free(list);
	return (NULL);
}

int	lst_add_point(t_point_list *list, t_a_point *point)
{
	t_point_node	*node;

	if (!point)
		return (1);
	if (!list->points)
	{
		list->points = make_point_node(point);
		if (!list->points)
			return (1);
		return (0);
	}
	node = list->points;
	while (node)
	{
		if (!node->next)
			break ;
		node = node->next;
	}
	node->next = make_point_node(point);
	if (!node->next)
		return (1);
	return (0);
}

void	print_point_list(t_point_list *list) 
{
	t_point_node	*node;
	int				counter;

	if (!list)
		return ;
	node = list->points;
	counter = 1;
	while (node)
	{
		ft_printf("%d) node : %d %d\n", counter, node->point->x/64, node->point->y/64);
		node = node->next;
		counter += 1;
	}
}