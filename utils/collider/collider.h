/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:59:04 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 22:34:49 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLIDER_H
# define COLLIDER_H

# include <math.h>
# include <stdlib.h>

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef enum s_intersection
{
	INTER_NONE = 0,
	INTER_STRAIGHT = 1,
	INTER_BACK = 2,
	INTER_UP = 3,
	INTER_DOWN = 4,
}			t_intersection;

typedef struct s_collider
{
	int		*x;
	int		*y;
	int		height;
	int		width;
	int		align_top;
	int		align_left;
	t_point	*top_l;
	t_point	*top_r;
	t_point	*bot_l;
	t_point	*bot_r;
}			t_collider;

t_point		*make_point(int x, int y);
void		update_point(t_point *point, int x, int y);
void		free_point(t_point *point);
void		shift_point(t_point *point, int x, int y);
t_collider	*make_collider(int height, int width, int *x, int *y);
void		free_collider(t_collider *collider);
void		shift_collider(t_collider *coll, int x, int y);
void		sync_collider(t_collider *coll);
int			check_intersection(t_collider *col1, t_collider *col2, int target,
				int speed);
t_collider	*coll_set_align(t_collider *coll, int top, int left);
int			inter_straight(t_collider *col1, t_collider *col2, int speed);
int			inter_back(t_collider *col1, t_collider *col2, int speed);
int			inter_up(t_collider *col1, t_collider *col2, int speed);
int			inter_down(t_collider *col1, t_collider *col2, int speed);
int			inter_here(t_collider *col1, t_collider *col2);

void		update_collider(t_collider *coll);
t_point		*coll_upd_top_left(t_collider *collider, int x, int y);
t_point		*coll_upd_top_right(t_collider *collider, int x, int y);
t_point		*coll_upd_bot_right(t_collider *collider, int x, int y);
t_point		*coll_upd_bot_left(t_collider *collider, int x, int y);

int			inter_segm(t_point *p1, t_point *p2, t_point *q1, t_point *q2);
#endif // !COLLIDER_H