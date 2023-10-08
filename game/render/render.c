/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:51:46 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/08 19:11:00 by tmazitov         ###   ########.fr       */
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
		anime = game->player->anime->idle;
	// printf("anime: %p\n", anime);
	tile = get_next_tile(anime);
	x = game->player->x - (game->player->coll->width / 2);
	y = game->player->y - game->player->coll->height;
	mlx_put_image_to_window(game->mlx, game->window, tile->image, x, y);
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
	t_tree	**trees;
	t_tree	*tree;

	counter = 0;
	trees = game->scene->trees;
	while (trees[counter])
	{
		tree = trees[counter];
		x = tree->x - (tree->width - tree->coll->width) / 2;
		y = tree->y - tree->height + (tree->coll->height / 2) + 8;
		mlx_put_image_to_window(game->mlx, game->window, tree->image, x, y);
		counter++;
	}

	return 0;
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
	while(scene->trees[coll_ctn])
	{
		draw_collider(game, scene->trees[coll_ctn]->coll);
		coll_ctn++;
	}
	draw_collider(game, game->player->coll);
	return (0);
}



int	render_hook(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	render_scene(game);
	render_player(game);
	render_trees(game);
	render_colliders(game);
	return (0);	
}
