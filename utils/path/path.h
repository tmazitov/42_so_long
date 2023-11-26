/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:59:35 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/26 20:56:33 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

#include <stdlib.h>
#include <stdio.h>

# ifndef NEIGHBOUR_DISTANCE
#  define NEIGHBOUR_DISTANCE 64
# endif

typedef	struct s_a_point
{
	int					x;
	int					y;
	int					weight;
	int					heuristic_approxim;
	int					passed_way;
	struct s_a_point	*origin;
}		t_a_point;

typedef struct s_point_node
{
	t_a_point			*point;
	struct s_point_node	*next;
}		t_point_node;


typedef	struct s_point_list
{
	t_point_node	*points;
}		t_point_list;

typedef struct s_a_store
{
	t_a_point		*dest;
	t_point_list	*game_objs;
	t_point_list	*opened;
	t_point_list	*closed;
}		t_a_store;

// cacl_path return the path from enemy to the player
t_point_list	*calc_path(t_a_point *src, t_a_point *dest, t_point_list *g_objs);

// POINT

t_a_point		*make_a_point(int x, int y, t_a_point *origin);
void			*free_a_point(t_a_point *point);
void 			pnt_calc_weight(t_a_point *point, t_a_point *dest);

// POINT NODE

t_point_node	*make_point_node(t_a_point *point);
void			*free_point_node(t_point_node *node);

// POINT LIST

t_point_list	*make_point_list();
int				lst_add_point(t_point_list *list, t_a_point *point);
t_a_point		*lst_get_min_point(t_point_list *list);
void			lst_rem_point(t_point_list *list, t_a_point *point);
t_a_point		*lst_check_by_coord(t_point_list *list, int x, int y);
void			*free_point_list(t_point_list *list);

// A* ALG STORAGE

t_a_store		*make_a_store(t_a_point *src, t_a_point *dest, t_point_list *g_objs);
void			*free_a_store(t_a_store	*store);
t_a_point		*a_check_by_coords(t_a_store *store, int x, int y);

#endif // !PATH_H