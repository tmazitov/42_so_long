/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:44:50 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/01 12:34:26 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	*free_task(t_player_task *task)
{
	free(task);
	return (NULL);
}

t_player_task	*make_task(t_action action, t_anime *anime)
{
	t_player_task	*task;

	task = malloc(sizeof(t_player_task));
	if (!task)
		return (NULL);
	task->anime = anime;
	task->action = action;
	task->next = NULL;
	return (task);
}

