# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 12:50:49 by kdrissi-          #+#    #+#              #
#    Updated: 2021/12/16 13:05:55 by kdrissi-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=./src/main.c ./src/parsing.c ./src/split_pipes.c  ./src/utils.c ./libs/minidict/insert_ops.c ./libs/minidict/search_ops.c ./libs/minidict/delete_ops.c \
./src/builtins/cd.c ./src/builtins/unset.c ./src/builtins/echo.c ./src/builtins/export.c ./src/builtins/pwd.c ./src/builtins/env.c 
NAME= minishell
#FLAGS= -Wall -Werror -Wextra
LIBS = -lreadline
LIBFT = ./libs/libft/libft.a
FLAGS= -fsanitize=address

all: $(NAME)

$(NAME): $(SRCS)
		make -C ./libs/libft
		gcc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME) $(LIBS)

clean:
		make -C ./libs/libft clean

fclean:
		make -C ./libs/libft fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re

test:
	make -C ./libs/libft