/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:51:46 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/02 16:42:17 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int render_player_health_bar(t_game *game)
{
	int		x;
	int		y;
	t_image *image;


	image = hb_get_image(game->player->health);	
	if (!image)
		return (0);
	x = game->player->x;
	y = game->player->y - image->height;
	mlx_put_image_to_window(game->mlx, game->window, image->content, x, y);
	return (0);
}
int render_enemy_health_bar(t_game *game)
{
	t_enemy			**enemies;
	t_enemy			*enemy;
	int				counter;
	t_image			*image;
	int				x;
	int				y;

	counter = 0;
	enemies = game->scene->enemies;
	while (enemies[counter])
	{
		enemy = enemies[counter];
		image = hb_get_image(enemy->health);
		if (image)
		{
			x = enemy->x;
			y = enemy->y - image->height;
			mlx_put_image_to_window(game->mlx, game->window, image->content, x, y);
		}
		counter++;
	} 
	return (0);
}

int render_player(t_game *game)
{
	int		x;
	int		y;
	t_anime_tile	*tile;
	t_anime			*anime;

	anime = NULL;
	// printf("task %p\n", game->player->current_task);
	if (game->player->current_task)
		anime = task_proccess(game->scene, game->player);
	if (!anime)
		anime = pl_idle_anime(game->player);
	// printf("anime: %p\n", anime);
	tile = get_next_tile(anime);
	x = game->player->x - (game->player->coll->width / 2) + 16;
	y = game->player->y - (game->player->coll->height / 2);
	mlx_put_image_to_window(game->mlx, game->window, tile->image, x, y);
	return (0);
}

int render_enemy_path(t_game *game, t_enemy *enemy)
{
	int	x;
	int	y;
	int x_b;
	int y_b;
	t_point_node	*node;

	if (!enemy->path)
		return (0);

	x = 0;
	y = 0;
	node = enemy->path->point_list->points;
	while (node)
	{
		while (x < 64)
		{
			y = 0;
			while (y < 64)
			{
				if (x <= 27 || x >= 37 || y <= 27 || y >= 37)
				{
					y++;
					continue;
				}
				x_b = node->point->x + x;
				y_b = node->point->y + y;
				mlx_pixel_put(game->mlx, game->window, x_b, y_b, 0xdb5c62);
				y++;
			}
			x++;
		}
		x = 0;
		node = node->next;
	}

	return (0);
}

int render_enemy(t_game	*game)
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
			return (1);
		enemy_tile = get_next_tile(anime);
		mlx_put_image_to_window(game->mlx, game->window, enemy_tile->image, enemy->x, enemy->y);
		counter++;
	} 
	return (0);
}



int	render_scene(t_game *game)
{
	int		x;
	int		y;
	void	*image;

	x = 0;
	image = game->scene->textures->grass;
	while (x < game->scene->width)
	{
		y = 0;
		while (y < game->scene->height)
		{
			mlx_put_image_to_window(game->mlx, game->window, image, x, y);
			y += 128;
		}
		x += 128;	
	}
	
	return (0);
}

int render_trees(t_game *game)
{
	int 	counter;
	int 	x;
	int 	y;
	t_scene_obj	**objs;
	t_scene_obj	*obj;

	counter = 0;
	objs = game->scene->objs;
	while (objs[counter])
	{
		if (!objs[counter]->is_render)
		{
			counter++;
			continue;
		}
		obj = objs[counter];
		if (obj->type == OBJ_TREE)
		{
			x = obj->x - (obj->width - obj->coll->width) / 2;
			y = obj->y - (obj->height - obj->coll->height) / 2 - 28;
		}
		else if (obj->type == OBJ_STONE)
		{
			x = obj->x;
			y = obj->y;
		}
		mlx_put_image_to_window(game->mlx, game->window, obj->image, x, y);
		counter++;
	}

	return 0;
}

int	render_chests(t_game *game)
{
	void	*chest_image;
	t_chest	**chests;
	t_chest	*chest;
	int		counter;

	counter = 0;
	chests = game->scene->chests;
	while (chests[counter])
	{
		chest = chests[counter];
		chest_image = render_chest(chest);
		mlx_put_image_to_window(game->mlx, game->window, chest_image, chest->obj->x, chest->obj->y);
		counter++;
	} 
	return (0);
}

int	draw_collider(t_game *game, t_collider *coll)
{
	int	x;
	int	y;
	int x_b;
	int y_b;

	x = 0;
	y = 0;
	while (x < coll->width)
	{
		y = 0;
		while (y < coll->height)
		{
			if (x != 0 && x != coll->width - 1 && y != 0 && y != coll->height - 1)
			{
				y++;
				continue;
			}
			x_b = *coll->x + x;
			y_b = *coll->y + y;
			mlx_pixel_put(game->mlx, game->window, x_b, y_b, 0b111100001111000000111110);
			y++;
		}
		x++;
	}
	return (0);
}
int	draw_hit_box(t_game *game, t_collider *hit_box)
{
	int	x;
	int	y;
	int x_b;
	int y_b;

	x = 0;
	y = 0;
	while (x < hit_box->width)
	{
		y = 0;
		while (y < hit_box->height)
		{
			if (x != 0 && x != hit_box->width - 1 && y != 0 && y != hit_box->height - 1)
			{
				y++;
				continue;
			}
			x_b = *hit_box->x + hit_box->align_top + x;
			y_b = *hit_box->y + hit_box->align_left + y;
			mlx_pixel_put(game->mlx, game->window, x_b, y_b, 0xa6130c);
			y++;
		}
		x++;
	}
	return (0);
}

int render_colliders(t_game	*game)
{
	t_scene *scene;
	int		coll_ctn;
	
	scene = game->scene;
	coll_ctn = 0;
	while(scene->objs[coll_ctn])
	{
		draw_collider(game, scene->objs[coll_ctn]->coll);
		coll_ctn++;
	}
	coll_ctn = 0;
	while(scene->enemies[coll_ctn])
	{
		draw_collider(game, scene->enemies[coll_ctn]->coll);
		coll_ctn++;
	}
	draw_collider(game, game->player->coll);
	return (0);
}
int render_hit_box(t_game *game)
{
	t_scene *scene;
	int		coll_ctn;
	
	scene = game->scene;
	coll_ctn = 0;
	while(scene->enemies[coll_ctn])
	{
		draw_hit_box(game, scene->enemies[coll_ctn]->hit_box);
		coll_ctn++;
	}
	draw_hit_box(game, game->player->hit_box);
	return (0);
}

int	render_hook(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	render_scene(game);
	render_chests(game);
	render_enemy(game);
	render_player(game);
	render_trees(game);
	render_player_health_bar(game);
	render_enemy_health_bar(game);
	// render_colliders(game);
	// render_hit_box(game);
	return (0);
}
