# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgena <mgena@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 20:50:25 by mgena             #+#    #+#              #
#    Updated: 2020/01/13 17:48:55 by mgena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ls
SRCS_PATH=./srcs/
SRCS_FILES= main.c ft_ls.c fill.c list_func.c lst_func_more.c print_large.c \
            		ft_mult_args.c print.c errors.c print2.c
SRCS=$(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJECTS_PATH=./objects
OBJECTS_FILES=$(SRCS_FILES:.c=.o)
OBJECTS=$(addprefix $(OBJECTS_PATH), $(OBJECTS_FILES))
INCLUDES=-Iincludes -Iincludes/libft -Iincludes/ft_printf/includes
CC=gcc -Wall -Wextra -Werror $(INCLUDES)
LIB_NAME=ft
LIB_PATH=includes/libft
FT_PRINTF_NAME=ftprintf
FT_PRINTF_PATH=includes/ft_printf/
VPATH=. srcs/ includes/ includes/libft includes/ft_printf 
all: $(NAME)
$(NAME): $(OBJECTS) $(HEADER)
	@make -C $(LIB_PATH)
	@make -C $(FT_PRINTF_PATH)
	$(CC) $(OBJECTS) -L$(LIB_PATH) -L$(FT_PRINTF_PATH) -l$(LIB_NAME) -l$(FT_PRINTF_NAME) -o $(NAME)
$(OBJECTS_PATH)%.o: $(SRCS_PATH)%.c
	$(COMPILE) $(INCLUDES) -c $< -o $@
clean:
	@make -C $(FT_PRINTF_PATH) clean
	@make -C $(LIB_PATH) clean
	@rm -rf $(OBJECTS_PATH)
	@rm -rf $(OBJECTS)
fclean: clean
	@make -C $(FT_PRINTF_PATH) fclean
	@make -C $(LIB_PATH) fclean
	@rm -rf $(NAME)
re: fclean all
.PHONY: clean fclean re all
