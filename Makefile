# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 12:50:49 by kdrissi-          #+#    #+#              #
#    Updated: 2022/02/07 05:04:51 by moerradi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=./src/utils/debug_utils.c ./src/parsing/removechars.c				\
	./src/parsing/inits.c ./src/parsing/parse_quotes.c					\
	./src/parsing/parsing.c ./src/parsing/cleanup.c						\
	./src/parsing/split_pipes.c ./src/parsing/parse_tokens.c			\
	./src/utils/general_utils.c ./src/utils/env_utils.c					\
	./src/builtins/cd.c ./src/builtins/unset.c ./src/builtins/echo.c	\
	./src/builtins/export.c ./src/builtins/pwd.c ./src/builtins/env.c	\
	./src/exec/run_cmd.c ./src/exec/get_i_o.c ./src/exec/ft_execvp.c	\
	./src/builtins/exit.c ./src/utils/ft_putenv.c						\
	./src/utils/exec_utils.c ./src/utils/ascii_art.c ./src/utils/termcaps.c
MAIN=./src/main.c

NAME= minishell
FLAGS= -Wall -Werror -Wextra
LIBS = -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include -ltermcap
LIBFT = ./libs/libft/libft.a
ANTILEAKS= -fsanitize=address

all: $(NAME)

$(NAME): $(SRCS) $(MAIN)
		make -C ./libs/libft
		make -C ./libs/libft bonus
		gcc $(FLAGS) $(SRCS) $(MAIN) $(LIBFT) -o $(NAME) $(LIBS)

sanitize: $(SRCS)
	make -C ./libs/libft
	make -C ./libs/libft bonus
	gcc $(FLAGS) $(ANTILEAKS) $(SRCS) $(MAIN) $(LIBFT) -o $(NAME) $(LIBS)

clean:
		make -C ./libs/libft clean

fclean:
		make -C ./libs/libft fclean
		rm -rf $(NAME)
test: $(SRC) testcase.c
		make -C ./libs/libft
		make -C ./libs/libft bonus
		gcc $(FLAGS) $(SRCS) testcase.c $(LIBFT) -o test $(LIBS) $(ANTILEAKS) -g

re: fclean all

.PHONY: clean fclean all re
