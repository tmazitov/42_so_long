/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_road_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:21:38 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:15:32 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_image	*get_start_tile(t_step next_step, t_scene *s)
{
	if (next_step == TO_BOT)
		return (s->textures->roads[ROAD_NONE_BOT]);
	if (next_step == TO_TOP)
		return (s->textures->roads[ROAD_NONE_TOP]);
	if (next_step == TO_RIGHT)
		return (s->textures->roads[ROAD_NONE_RIGHT]);
	if (next_step == TO_LEFT)
		return (s->textures->roads[ROAD_NONE_LEFT]);
	return (NULL);
}

t_image	*get_end_tile(t_step next_step, t_scene *s)
{
	if (next_step == TO_BOT)
		return (s->textures->roads[ROAD_NONE_TOP]);
	if (next_step == TO_TOP)
		return (s->textures->roads[ROAD_NONE_BOT]);
	if (next_step == TO_RIGHT)
		return (s->textures->roads[ROAD_NONE_LEFT]);
	if (next_step == TO_LEFT)
		return (s->textures->roads[ROAD_NONE_RIGHT]);
	return (NULL);
}

t_image	*get_tile(t_step prev, t_scene *s)
{
	if (prev == TO_BOT || prev == TO_TOP)
		return (s->textures->roads[ROAD_TOP_TOP]);
	if (prev == TO_LEFT || prev == TO_RIGHT)
		return (s->textures->roads[ROAD_RIGHT_RIGHT]);
	return (NULL);
}
