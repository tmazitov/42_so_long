/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_bar.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:53:15 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/02 19:25:07 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEALTH_BAR_H
# define HEALTH_BAR_H

#include <stdlib.h>
#include "../../utils/image/image.h"

# define HEALTH_BAR_BORDER_C 0x222529
# define HEALTH_BAR_HEALTH_C 0xe2725b

typedef	struct s_health_bar
{
	int		max;
	int		current;
	t_image	**images;
}		t_health_bar;

t_health_bar	*make_health_bar(void *mlx, int max);
t_image			*hb_get_image(t_health_bar *bar);
void			hb_update(t_health_bar *bar, int value);
void			*free_health_bar(t_health_bar *bar);
t_image			*make_health_bar_image(void *mlx , t_health_bar *bar, int count);
#endif // !HEALTH_BAR_H