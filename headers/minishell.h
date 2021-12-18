/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:16:44 by moerradi          #+#    #+#             */
/*   Updated: 2021/12/18 16:45:16 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#define IGNORE_ALL	"$ \t\\'\"|~"
#define DQUOTE_IGNORE " \t'|~"

typedef	struct		s_pipe
{
	char	*output_file;
	char	*input_file;
	char	*command;
	char	**args;
}				t_pipe;

extern t_dict	*g_env;
int	env(void);

#endif