/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:17:39 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/10 20:17:39 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char **g_env;

void	init_environ(char **envir)
{
	int	i;

	i = 0;
	while (envir[i])
		i++;
	g_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envir[i])
	{
		g_env[i] = ft_strdup(envir[i]);
		i++;
	}
	g_env[i] = NULL;
	set_exit(0);
}

char	*prompt(void)
{
	char	*cwd;
	char	*prompt_msg;
	char	*out;

	cwd = getcwd(NULL, 4096);
	prompt_msg = ft_strrchr(cwd, '/') + 1;
	prompt_msg = ft_strjoin(prompt_msg, " > ");
	out = readline(prompt_msg);
	free(cwd);
	free(prompt_msg);
	return (out);
}

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		if (ft_strcmp(rl_line_buffer, ""))
			exit(131);
	}
}

int	main(int argc, char **argv, char **envir)
{
	char	*raw_line;
	char	*tmp;
	t_list	*pipes;
	
	init_environ(envir);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	while (1)
	{
		tmp = prompt();
		raw_line = ft_strtrim(tmp, " \t");
		if (!tmp)
		{
			rl_clear_history();
			exit(0);
		}
		if (!(*raw_line))
		{
			free(raw_line);
			free(tmp);
			continue ;
		}
		pipes = parse(raw_line);
		free(raw_line);
		if (!pipes)
		{
			printf("Parse error\n");
			continue ;
		}
		add_history(tmp);
		free(tmp);
		// ft_lstiter(pipes, &deb_print_pipe);
		run_cmd(pipes);
		ft_lstclear(&pipes, &free_pipe);
	}
}
