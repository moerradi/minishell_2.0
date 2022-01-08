/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:16:44 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/08 23:25:36 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libs/libft/libft.h"
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
# include <fcntl.h>

# define IGNORE_ALL		"$ \\'\"|~<>"
# define DQUOTE_IGNORE	" '|~<>"
# define EQUOTE_IGNORE	"\\\"$"
# define R_CREATE		1
# define R_APPEND		2
# define R_READ			3
# define R_STREAM		4

typedef enum e_token {nontoken, s_in, s_out, d_in, d_out, dollar }t_token;

typedef struct s_redir
{
	char	*file;
	t_token	mode;
}				t_redir;

typedef struct s_pipe
{
	t_list	*output_files;
	t_list	*input_files;
	char	*cmd;
	int		ac;
	char	**args;
}			t_pipe;

void	fix_token(char *str);
t_redir	*redir_new(char *path, t_token mode);
t_pipe	*init_pipe(void);
char	*parse_quotes(char *line);
char	**split_pipes(char *s);
t_token	get_token_type(char	*token);
bool	validate_redirs(char **tokens);
char	*removechars(char *str, const char *charset);
t_pipe	*parse_tokens(char **tokens);
char	*expand(char *key);
void	free_pipe(void	*pipe);
void	free_strs(char **strs);
void	free_str(void *str);
char	*ret_free(char *str);
char	**mini_split(char *av, char c);
char	*expand_str(char *str);
char	**lst_to_arr(t_list	*lst, size_t size);
char	**extok(char *str, const char *set);
char	**adv_split(char *str, char c);
char	*handle_env(char *str);
t_list	*parse(char *cmd);
//debug utils
// #ifdef DEBUG
void	deb_print_strarr(char **strs);
void	deb_print_pipe(void *pipe);
// execution
void	ft_execvp(char *cmd, char **args);
void	free_redir(void *redir);
int		out_files(t_list *files);
int		handle_d_i(t_redir *tmp);
int		in_files(t_list *files);
void	run_cmd(t_list *cmd);
// builtins
int		cd(char **args, int args_count);
int		echo(char **args, int ac);
int		env(void);
int		bash_exit(char **args, int ac);
bool	ft_isnumeric(char	*str);
int		export(char **args, int ac);
int		pwd(char **args, int args_count);
int		unset(char **args);
void	get_i_o(t_pipe *cmd, int *in, int *out, int fd[2]);
int		str_alnum(char *str);
#endif