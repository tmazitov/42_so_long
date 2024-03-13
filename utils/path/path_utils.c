/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:14:51 by tmazitov          #+#    #+#             */
/*   Updated: 2024/03/13 12:26:54 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

void	print_path(t_path *path) 
{
	if (!path)
		return ;
	ft_printf("path length : %d\n", path->length);
	ft_printf("-----------------\n");
	print_point_list(path->point_list);
}	