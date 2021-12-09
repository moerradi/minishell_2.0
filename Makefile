SRCS=./src/main.c
NAME= minishell
#FLAGS= -Wall -Werror -Wextra
LIBS = -lreadline
LIBFT = ./libs/libft/libft.a

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