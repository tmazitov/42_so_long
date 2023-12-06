# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 14:16:32 by tmazitov          #+#    #+#              #
#    Updated: 2023/12/06 13:37:29 by tmazitov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRC =	cmd/main.c \
		game/game.c \
		game/player_behavior.c \
		game/enemy_behavior.c \
		game/enemy_move_check.c \
		game/enemy_move.c \
		game/enemy_attack.c \
		game/enemy/enemy.c \
		game/enemy/enemy_anime.c \
		game/enemy/enemy_movement.c \
		game/enemy/enemy_task.c \
		game/enemy/enemy_die_anime.c \
		game/enemy/enemy_idle_anime.c \
		game/enemy/enemy_move_anime.c \
		game/player/anime.c \
		game/player/player_idle_anime.c \
		game/player/anime_attack.c \
		game/player/player.c \
		game/player/player_attack.c \
		game/player/task.c \
		game/player/task_action.c \
		game/player/task_utils.c \
		game/player/task_check.c \
		game/health_bar/health_bar.c \
		game/health_bar/health_bar_image.c \
		game/health_bar/health_bar_update.c \
		game/render/render.c \
		game/render/render_scene.c \
		game/render/render_enemy.c \
		game/render/render_player.c \
		game/render/render_support.c \
		game/scene/scene.c \
		game/scene/scene_free.c \
		game/scene/scene_feel.c \
		game/scene/scene_obj.c \
		game/scene/scene_textures.c \
		game/scene/scene_tree.c \
		game/scene/tree.c \
		game/scene/chest.c \
		game/scene/chest_anime.c \
		game/parser/parser.c \
		game/parser/parser_noda.c \
		game/parser/parser_utils.c \
		game/parser/parser_validation.c \
		utils/image/image.c \
		utils/path/a_star.c \
		utils/path/a_star_check.c \
		utils/path/path.c \
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
		utils/collider/intersection.c \
		utils/collider/intersection_variants.c \
		utils/gnl/get_next_line.c \
		utils/gnl/get_next_line_utils.c \
		

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

# LIB = cd libft && make

MLX = cd mlx && make

# MYPRINTF = cd printf42 && make

# 		$(LIB)
#		$(MYPRINTF)
# $(OBJ): $(SRC)
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ) 
		$(MLX)
		gcc $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -fsanitize=address -g
# 
# -Lmlx -lmlx
# libft/libft.a printf42/libftprintf.a
# -framework OpenGL -framework AppKit

all: $(NAME)

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C mlx
#		cd libft && make clean
#		cd printf42 && make clean
fclean: clean
		rm -f $(NAME)
# 		cd libft && make fclean
# 		cd printf42 && make fclean
re:		fclean all
#		cd libft && make fclean && make all
#0		cd printf42 && make fclean && make all

.PHONY:	all clean fclean re