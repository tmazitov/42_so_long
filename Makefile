# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 14:16:32 by tmazitov          #+#    #+#              #
#    Updated: 2024/03/13 13:07:17 by tmazitov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRC =	cmd/main.c \
		cmd/hooks.c \
		game/game.c \
		game/game_writer.c \
		game/enemy/enemy.c \
		game/enemy/enemy_anime.c \
		game/enemy/enemy_movement.c \
		game/enemy/enemy_task.c \
		game/enemy/enemy_die_anime.c \
		game/enemy/enemy_idle_anime.c \
		game/enemy/enemy_move_anime.c \
		game/enemy_behavior/enemy_behavior.c \
		game/enemy_behavior/enemy_move_check.c \
		game/enemy_behavior/enemy_move.c \
		game/enemy_behavior/enemy_attack.c \
		game/player/player.c \
		game/player/player_anime.c \
		game/player/player_die_anime.c \
		game/player/player_idle_anime.c \
		game/player/player_move_anime.c \
		game/player/player_attack.c \
		game/player/player_attack_anime.c \
		game/player/player_task.c \
		game/player/player_task_action.c \
		game/player/player_task_utils.c \
		game/player/player_task_check.c \
		game/player_behavior/player_behavior.c \
		game/health_bar/health_bar.c \
		game/health_bar/health_bar_image.c \
		game/health_bar/health_bar_update.c \
		game/render/render.c \
		game/render/render_exit.c \
		game/render/render_scene.c \
		game/render/render_enemy.c \
		game/render/render_player.c \
		game/render/render_player_road.c \
		game/render/render_player_road_utils.c \
		game/render/render_support.c \
		game/render/render_itoa.c \
		game/scene/scene.c \
		game/scene/scene_free.c \
		game/scene/scene_feel.c \
		game/scene/scene_obj.c \
		game/scene/scene_textures.c \
		game/scene/scene_textures_roads.c \
		game/scene/scene_tree.c \
		game/scene/scene_exit.c \
		game/scene/tree.c \
		game/scene/chest.c \
		game/scene/chest_utils.c \
		game/scene/chest_anime.c \
		game/parser/parser.c \
		game/parser/parser_node.c \
		game/parser/parser_utils.c \
		game/parser/parser_error.c \
		game/parser/parser_validation.c \
		utils/image/image.c \
		utils/path/a_star.c \
		utils/path/a_star_check.c \
		utils/path/path.c \
		utils/path/path_utils.c \
		utils/path/point.c \
		utils/path/point_node.c \
		utils/path/point_path.c \
		utils/path/point_list.c \
		utils/path/point_list_utils.c \
		utils/path/point_list_check.c \
		utils/anime/anime.c \
		utils/anime/anime_tile.c \
		utils/collider/point.c \
		utils/collider/collider.c \
		utils/collider/collider_update.c \
		utils/collider/collider_shift.c \
		utils/collider/intersection.c \
		utils/collider/intersection_variants.c \
		utils/gnl/get_next_line.c \
		utils/gnl/get_next_line_utils.c \
		utils/printf/ft_printf.c \
		utils/printf/ft_puthex.c \
		utils/printf/ft_putchar.c \
		utils/printf/ft_putstr.c \
		utils/printf/ft_putnbr.c \
		utils/printf/ft_putunbr.c \
		utils/mlx_font_print/writer.c \
		utils/mlx_font_print/writer_symbol.c \
		utils/mlx_font_print/writer_handler.c \
		
OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLX = cd mlx && make
MLX_LIN = cd mlx_linux && make

$(NAME): $(OBJ) 
	$(MLX)
	gcc $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

lin: $(OBJ) 
	$(MLX_LIN)
	gcc $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C mlx

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re