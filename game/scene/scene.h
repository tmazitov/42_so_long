/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:32:11 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/02 15:53:06 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

#include <stdlib.h>
#include "../../mlx/mlx.h"

typedef struct s_scene_textures
{
	void	*grass;
}		t_scene_textures;


typedef struct s_scene
{
	char				**raw;
	t_scene_textures	*textures;
	int					width;
	int					height;
}		t_scene;

t_scene *make_scene(void *mlx, int height, int width);

#endif 