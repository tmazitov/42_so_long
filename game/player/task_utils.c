/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:32:07 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/01 12:44:00 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int task_count(t_player_task *task)
{
	if (!task)
		return (0);
	if (task->next)
		return (task_count(task->next) + 1);
	return (1);
}

