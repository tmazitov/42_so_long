NAME = libftprintf.a

VPATH = .

SRCS= ft_printf.c \
ft_puthex.c \
ft_putchar.c \
ft_putstr.c \
ft_putnbr.c \
ft_putunbr.c \

OBJS=$(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJS)
	ar -r $(NAME) $?

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus

