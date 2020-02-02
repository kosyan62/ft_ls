# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkingsbl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 02:21:08 by pkingsbl          #+#    #+#              #
#    Updated: 2020/01/13 17:03:57 by mgena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

PATH_LIBFT = ../libft

SRC = ft_printf.c ft_new.c ft_itoa_base.c ft_for_p.c \
		percent.c type_s.c type_c.c type_i_d.c ldbl_copy.c \
		ldbl_extract.c long_math.c rounding.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(PATH_LIBFT)/libft.a $(OBJ)
	$(CC) $(CFLAGS) -I libftprintf.h -c $(SRC) 
	@cp $(PATH_LIBFT)/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(PATH_LIBFT)/libft.a:
	make -C $(PATH_LIBFT)

%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< 

clean:
	rm -f $(OBJ)
	make -C $(PATH_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
