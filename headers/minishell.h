#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>

typedef struct		s_cmd
{
}					t_cmd;

typedef struct		s_envvar
{
	char	*key;
	char	*value;
}					t_envvar;

#endif