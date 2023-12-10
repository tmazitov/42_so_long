/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:33:13 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:13:46 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_enemy_health_bar(t_game *game)
{
	t_enemy	**enemies;
	int		counter;
	t_image	*image;
	int		x;
	int		y;

	counter = 0;
	enemies = game->scene->enemies;
	while (enemies[counter])
	{
		image = hb_get_image(enemies[counter]->health);
		if (image)
		{
			x = enemies[counter]->x;
			y = enemies[counter]->y - image->height;
			mlx_put_image_to_window(game->mlx, game->window, image->content, x,
				y);
		}
		counter++;
	}
}

void	render_enemy(t_game *game)
{
	t_anime_tile	*enemy_tile;
	t_enemy			**enemies;
	t_enemy			*enemy;
	t_anime			*anime;
	int				counter;

	counter = 0;
	enemies = game->scene->enemies;
	while (enemies[counter])
	{
		enemy = enemies[counter];
		anime = exec_enemy_behavior(game->player, game->scene, enemy);
		if (!anime)
			return ;
		if (enemy->is_go_back)
			enemy_tile = get_next_tile_rev(anime);
		else
			enemy_tile = get_next_tile(anime);
		mlx_put_image_to_window(game->mlx, game->window, enemy_tile->image,
			enemy->x, enemy->y);
		counter++;
	}
}

// int render_enemy_path(t_game *game, t_enemy *enemy)
// {
// 	int	x;
// 	int	y;
// 	int x_b;
// 	int y_b;
// 	t_point_node	*node;

// 	if (!enemy->path)
// 		return (0);
// 	x = 0;
// 	y = 0;
// 	node = enemy->path->point_list->points;
// 	while (node)
// 	{
// 		while (x < 64)
// 		{
// 			y = 0;
// 			while (y < 64)
// 			{
// 				if (!(x <= 27 || x >= 37 || y <= 27 || y >= 37))
// 				{
// 					x_b = node->point->x + x;
// 					y_b = node->point->y + y;
// 					mlx_pixel_put(game->mlx, game->window, x_b, y_b, 0xdb5c62);
// 				}
// 				y++;
// 			}
// 			x++;
// 		}
// 		x = 0;
// 		node = node->next;
// 	}
// 	return (0);
// }