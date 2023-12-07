/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:27:14 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/07 15:28:54 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int render_player_health_bar(t_game *game)
{
	int		x;
	int		y;
	int		res;
	t_image *image;

	image = hb_get_image(game->player->health);	
	if (!image)
		return (0);
	x = game->player->x;
	y = game->player->y - image->height;
	res = mlx_put_image_to_window(game->mlx, game->window, image->content, x, y);
	return (res);
}

int render_player_money(t_game *game)
{
	void	*mlx;
	int		res;
	void	*win;
	char	*money_str;

	mlx = game->mlx;
	win = game->window;
	res = mlx_string_put(mlx, win, 10, 10, 0xe6dddc, "Money!");
	money_str = ft_itoa(game->player->money);
	if (!money_str)
		return (1);
	res = mlx_string_put(mlx, win, 60, 10, 0xe6dddc, money_str);
	return (res);
}


int render_player(t_game *game)
{
	int				x;
	int				y;
	int				res;
	t_anime_tile	*tile;
	t_anime			*anime;

	anime = NULL;
	if (game->player->current_task)
		anime = task_proccess(game->scene, game->player);
	if (!anime)
		anime = pl_idle_anime(game->player);
	if (game->player->attack_call_down)
		game->player->attack_call_down -= 1;
	tile = get_next_tile(anime);
	x = game->player->x - (game->player->coll->width / 2) + 16;
	y = game->player->y - (game->player->coll->height / 2);
	res = mlx_put_image_to_window(game->mlx, game->window, tile->image, x, y);
	return (res);
}