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

#define IGNORE_ALL	"$ \t\\'\"|~<>"
#define DQUOTE_IGNORE " \t'|~<>"
#define	EQUOTE_IGNORE "\\\"$"

#define	R_CREATE 1
#define R_APPEND 2
#define	R_READ 3
#define	R_STREAM 4

typedef	enum e_token {nontoken, si_redir, so_redir, di_redir, do_redir, dollar }t_token;

typedef struct	s_redir
{
	char	*file;
	t_token	mode;
}				t_redir;

typedef	struct		s_pipe
{
	t_list	*output_files;
	t_list	*input_files;
	char	*command;
	t_list	*args;
}				t_pipe;

extern t_dict	*g_env;

int		env(void);
void	fix_token(char *str);
t_redir	*redir_new(char *path, t_token mode);
t_pipe	*init_pipe();
char	*parse_quotes(char *line);
char	**split_pipes(char *s);
t_token	get_token_type(char	*token);
bool	validate_redirs(char **tokens);
t_pipe	*parse_tokens(char **tokens);
char	*expand(char *key);
void	free_pipe(void	*pipe);
void	free_strs(char **strs);

//debug utils
void	deb_print_strarr(char **pipes);


#endif