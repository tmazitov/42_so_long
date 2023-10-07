/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:59:04 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/07 23:05:34 by tmazitov         ###   ########.fr       */
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
}		t_collider;

t_point		*make_point(int x, int y);
t_collider	*make_collider(int height, int width, int *x, int *y);
void		free_collider(t_collider *collider);
int			check_intersection(t_collider *col1, t_collider *col2, int target, int speed);
#endif // !COLLAIDER_H