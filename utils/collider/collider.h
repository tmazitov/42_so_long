/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:59:04 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/08 18:29:28 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef COLLAIDER_H
# define COLLAIDER_H

#include <stdlib.h>
#include <math.h>

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;


typedef enum s_intersection{
	INTER_NONE		= 0,
	INTER_STRAIGHT	= 1,
	INTER_BACK 		= 2,
	INTER_UP 		= 3,
	INTER_DOWN 		= 4,
}		t_intersection;

typedef struct s_collider
{
	int		*x;
	int		*y;
	int		height;
	int		width;
	t_point	**points;
}		t_collider;

t_point		*make_point(int x, int y);
void		update_point(t_point *point, int x, int y);	
void		free_point(t_point *point);

t_collider	*make_collider(int height, int width, int *x, int *y);
void		free_collider(t_collider *collider);
int			check_intersection(t_collider *col1, t_collider *col2, int target, int speed);

t_point *coll_get_top_left(t_collider *collider);
t_point *coll_get_top_right(t_collider *collider);
t_point *coll_get_bot_right(t_collider *collider);
t_point *coll_get_bot_left(t_collider *collider);
t_point *coll_upd_top_left(t_collider *collider, int x, int y);
t_point *coll_upd_top_right(t_collider *collider, int x, int y);
t_point *coll_upd_bot_right(t_collider *collider, int x, int y);
t_point *coll_upd_bot_left(t_collider *collider, int x, int y);
#endif // !COLLAIDER_H