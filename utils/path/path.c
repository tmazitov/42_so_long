/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:59:26 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/28 11:03:49 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

static int add_neighbour(t_a_point *origin, t_a_store *store, int x, int y)
{
	t_a_point	*point;
	
	point = a_check_by_coords(store, x, y);
	if (point == NULL)
	{
		point = make_a_point(x, y, origin);
		if (lst_add_point(store->opened, point) != 0) 
			return (1);
		pnt_calc_weight(point, store->dest);
	}
	return (0);
}

static int make_neighbours(t_a_point *origin, t_a_store *store)
{
	int		dx;
	int		x;
	int		y;
	
	if (!origin || !store)
		return (1);
	dx = NEIGHBOUR_DISTANCE;
	x = origin->x;
	y = origin->y;
	if (add_neighbour(origin, store, x + dx, y) != 0)
		return (1);
	if (add_neighbour(origin, store, x - dx, y) != 0)
		return (1);
	if (add_neighbour(origin, store, x, y + dx) != 0)
		return (1);
	if (add_neighbour(origin, store, x, y - dx) != 0)
		return (1);
	return (0);
}

static t_point_list	*prepare_result(t_a_point *active)
{
	t_point_list	*result;
	t_a_point		*point;
	t_a_point		*new;
	t_a_point		*last;

	if (!active)
		return (NULL);
	result = make_point_list();
	if (!result)
		return (NULL);
	point = active;
	while (point) 
	{
		new = make_a_point(point->x, point->y, NULL);
		if (lst_add_point(result, new) != 0)
			return (free_point_list(result));
		if (!point->origin)
			break ;
		point = point->origin;
	}
	last = new;
	point = result->points->point;
	while (point && result->points->point != last) 
	{
		lst_rem_point(result, point);
		if (lst_add_point(result, point) != 0)
			return (free_point_list(result));
		if (!point->origin)
			break ;
		point = point->origin;
	}
	return (result);
}

t_point_list	*calc_path(t_a_point *src, t_a_point *dest, t_point_list *g_objs)
{
	t_point_list	*path;
	t_a_store		*store;
	t_a_point		*active;

	// printf("calc path:\n\tscr: %d %d\n\tdest: %d %d\n", src->x, src->y, dest->x, dest->y);
	store = make_a_store(src, dest, g_objs);
	if (!store)
		return (NULL);
	active = lst_get_min_point(store->opened);
	while (1)
	{

		if (make_neighbours(active, store) != 0)
			return (free_a_store(store));
		lst_rem_point(store->opened, active);
		lst_add_point(store->closed, active);
		if (active->heuristic_approxim == 0)
			break ;
		if (lst_length(store->opened) == 0)
			break ;
		active = lst_get_min_point(store->opened);
	}
	path = prepare_result(active);
	free_point_list(store->opened);
	free_point_list(store->closed);
	free_a_point(store->dest);
	free(store);
	return (path);
}

