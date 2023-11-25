/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:51:46 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/25 21:44:32 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int render_player(t_game *game)
{
	int		x;
	int		y;
	t_anime_tile	*tile;
	t_anime			*anime;

	anime = NULL;
	if (game->player->current_task)
		anime = task_proccess(game->scene, game->player);
	if (!anime)
	{
		if (game->player->last_movement == MOVE_DOWN)
			anime = game->player->anime->idle_up;
		else if (game->player->last_movement == MOVE_UP)
			anime = game->player->anime->idle_down;
		else if (game->player->last_movement == MOVE_STRAIGHT)
			anime = game->player->anime->idle_right;
		else if (game->player->last_movement == MOVE_BACK)
			anime = game->player->anime->idle_left;	
	}
	// printf("anime: %p\n", anime);
	tile = get_next_tile(anime);
	x = game->player->x ;
	y = game->player->y - (game->player->coll->height / 2);
	mlx_put_image_to_window(game->mlx, game->window, tile->image, x, y);
	return (0);
}

int render_enemy(t_game	*game)
{
	t_anime_tile	*enemy_tile;
	t_enemy	**enemies;
	t_enemy	*enemy;
	int		counter;

	counter = 0;
	enemies = game->scene->enemies;
	while (enemies[counter])
	{
		enemy = enemies[counter];
		enemy_tile = get_next_tile(enemy->anime->idle_left);
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



int	render_hook(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	render_scene(game);
	render_trees(game);
	render_chests(game);
	render_enemy(game);
	render_player(game);
	render_colliders(game);
	return (0);
}
