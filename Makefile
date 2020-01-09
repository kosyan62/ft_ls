# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgena <mgena@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 20:50:25 by mgena             #+#    #+#              #
#    Updated: 2020/01/09 20:59:33 by mgena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc
CFLAGS = -Wall -Wextra -Werror

PATH_LIBFT = srcs/libft

SRC = srcs/main.c srcs/ft_ls_greatthing.c srcs/fill.c srcs/list_func.c srcs/lst_func_more.c srcs/print_large.c

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