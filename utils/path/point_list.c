/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:07:14 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/26 21:14:08 by tmazitov         ###   ########.fr       */
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

int	lst_add_point(t_point_list *list, t_a_point *point)
{
	t_point_node *node;
	
	if (!point)
		return (1);
	// printf("\t add new point: %d %d\n", point->x, point->y);
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
	// printf("\tnode %p ---> next %p \n", node, node->next);
	if (!node->next)
		return (1);
	return (0);
}

void	lst_rem_point(t_point_list *list, t_a_point *point)
{
	t_point_node	*node;
	t_point_node	*prev;

	prev = NULL;
	node = list->points;
	while (node)
	{
		if (node->point == point) 
		{
			if (prev)
				prev->next = node->next;
			if (!prev && list->points == node)
				list->points = node->next;
			free(node);
			return ;			
		}

		prev = node;
		node = node->next;
	}
	return ;
}

t_a_point	*lst_get_min_point(t_point_list *list)
{
	int	min;
	t_point_node	*node;
	t_a_point		*point;

	if (!list || !list->points)
		return (NULL);
	min = INT32_MAX;
	point = NULL;
	node = list->points;
	while (node) 
	{
		if (node->point->weight < min)
		{
			min = node->point->weight;
			point = node->point;
		}
		node = node->next;
	}
	return (point);
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