# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 14:04:52 by cciapett          #+#    #+#              #
#    Updated: 2025/02/10 17:59:11 by cciapett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

LIB = -Lminilibx-linux -lmlx -lXext -lX11 -lm -Llibft -l:libft.a -Lft_printf -l:libftprintf.a

CFLAGS = -Wall -Werror -Wextra -g -Iminilibx-linux -Ilibft -Ift_printf

SRCS = main.c events.c events2.c julia.c mandelbrot.c utils.c converter.c

MINILB = 8

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft
	make -C ft_printf
	make -C minilibx-linux
	$(CC) $(SRCS) $(CFLAGS) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME)

re: fclean all

norminette:
	norminette $(SRCS) fractol.h

.PHONY: all clean fclean re
