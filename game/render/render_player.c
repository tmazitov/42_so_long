/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:27:14 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 23:10:20 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_player_health_bar(t_game *game)
{
	int		x;
	int		y;
	int		res;
	t_image	*image;
	void	*win;

	image = hb_get_image(game->player->health);
	if (!image)
		return ;
	win = game->window;
	x = game->player->x;
	y = game->player->y - image->height;
	res = mlx_put_image_to_window(game->mlx, win, image->content, x, y);
}

void	render_player_money(t_game *game)
{
	int		res;
	int		x;
	int		y;
	char	*money_str;

	x = 16;
	y = 16;
	x = mlx_print(game->writer, "MONEY", x, y);
	money_str = ft_itoa(game->player->money);
	if (!money_str)
		return ;
	res = mlx_print(game->writer, money_str, x, y);
	free(money_str);
}

void	render_player_score(t_game *game)
{
	int		res;
	int		x;
	int		y;
	char	*score_str;

	x = 16;
	y = 40;
	x = mlx_print(game->writer, "SCORE", x, y);
	score_str = ft_itoa(game->player->score);
	if (!score_str)
		return ;
	res = mlx_print(game->writer, score_str, x, y);
	free(score_str);
}

void	render_player(t_game *game)
{
	int				x;
	int				y;
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
	mlx_put_image_to_window(game->mlx, game->window, tile->image, x, y);
}
