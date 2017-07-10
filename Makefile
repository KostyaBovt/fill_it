#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartyno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 10:38:56 by omartyno          #+#    #+#              #
#    Updated: 2016/12/12 19:19:34 by kbovt            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
SRCS = basket_make.c check_figure.c error.c input.c main.c map_io.c \
map_make.c tetris.c ft_putchar.c ft_putstr.c ft_strcpy.c ft_strlen.c \
ft_strncpy.c
HEADERS = fillit.h
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror -o $@ $?

$(OBJS): $(HEADERS)

.c.o: $(SRCS)
	gcc -Wall -Wextra -Werror -I ./ -c $<

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
