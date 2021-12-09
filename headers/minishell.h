#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libs/libft/libft.h"
# include "../libs/minidict/minidict.h"
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



extern t_dict	*g_env;

#endif