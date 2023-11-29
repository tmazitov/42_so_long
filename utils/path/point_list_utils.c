/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:39:26 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/29 14:12:02 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

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
			else if (!prev && list->points == node && !node->next)
				list->points = NULL;
			else if (!prev && list->points == node)
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

int	lst_length(t_point_list *list) 
{
	int				length;
	t_point_node	*node;

	length = 0;
	node = list->points;
	while(node) 
	{
		length++;
		node = node->next;
	}
	return (length);
}

t_point_list	*lst_reverse(t_point_list *list)
{
	t_point_list	*result;
	t_point_node	*iter;
	int				length;
	int				counter;

	if (!list)
		return (NULL);
	result = make_point_list();
	if (!result)
		return (NULL);
	length = lst_length(list);
	while(1)
	{
		counter = 0;
		iter = list->points;
		while(iter && iter->next && counter != length - 1)
		{
			iter = iter->next;
			counter++;
		}
		length--;
		if (lst_add_point(result, make_a_point(iter->point->x, iter->point->y, NULL)) != 0)
			return (free_point_list(result));
		if (iter == list->points)
			break ;
	}
	return (result);
}