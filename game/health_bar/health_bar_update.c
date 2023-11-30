/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_bar_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:39:10 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/30 15:40:10 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "health_bar.h"

void	update_health_bar(t_health_bar *bar, int value)
{
	if (!bar || value < 0 || value > bar->max)
		return ;
	bar->current = value;
}