# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 14:16:32 by tmazitov          #+#    #+#              #
#    Updated: 2023/09/30 18:37:30 by tmazitov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRC =	cmd/main.c \
		game/game.c \
		game/player/anime.c \
		game/player/player.c \
		game/render/render.c \
		utils/anime/anime.c \
		utils/anime/anime_tile.c \
		

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
		gcc $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -fsanitize=address
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