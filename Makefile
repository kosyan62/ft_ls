# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkingsbl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 16:27:53 by pkingsbl          #+#    #+#              #
#    Updated: 2020/01/03 20:14:45 by mgena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc
CFLAGS =

PATH_LIBFT = libft

SRC = main.c ft_ls.c fill.c list_func.c lst_func_more.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(PATH_LIBFT)/libft.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L $(PATH_LIBFT) -lft

$(PATH_LIBFT)/libft.a:
	make -C $(PATH_LIBFT)

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -I $(PATH_LIBFT)

clean:
	rm -f $(OBJ)
	make -C $(PATH_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
