/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:17:39 by moerradi          #+#    #+#             */
/*   Updated: 2022/02/05 20:01:22 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	**g_env;

void	init_environ(char **envir)
{
	int	i;

	i = 0;
	while (envir[i])
		i++;
	g_env = (char **)malloc(sizeof(char *) * (i + 4));
	g_env[0] = ft_strdup("?=0");
	g_env[1] = ft_strdup("-flag=0");
	g_env[2] = ft_strdup("-screen=0");
	i = 0;
	while (envir[i])
	{
		g_env[i + 3] = ft_strdup(envir[i]);
		i++;
	}
	g_env[i + 3] = NULL;
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
	int	f;

	f = ft_atoi(ft_getenv("-flag"));
	if (sig == SIGINT)
	{
		if (!f)
		{
			set_exit(1);
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
	else if (sig == SIGQUIT)
	{
		if (!f)
		{
			ft_putstr_fd("\r\r", 1);
			rl_on_new_line();
			rl_redisplay();
		}
		else
			reset_terminal();
	}
}

void	loop(void)
{
	char	*raw_line;
	char	*tmp;
	t_list	*pipes;

	pipes = NULL;
	while (1)
	{
		ft_putenv("-flag=0");
		ft_putenv("-screen=0");
		tmp = prompt();
		raw_line = ft_strtrim(tmp, " \t");
		if (!tmp)
			exit(0);
		if (*raw_line)
			pipes = parse(raw_line);
		if (!pipes && *raw_line)
			ft_putstr_fd("Parse error !\n", 2);
		free(raw_line);
		if (*tmp)
			add_history(tmp);
		free(tmp);
		run_cmd(pipes);
		ft_lstclear(&pipes, &free_pipe);
	}
}

int	main(int argc, char **argv, char **envir)
{
	(void)argc;
	(void)argv;
	init_environ(envir);
	reset_terminal();
	ascii_art();
	if (signal(SIGINT, sig_handler) == SIG_ERR)
	{
		ft_putstr_fd("fatal error\n", 2);
		exit(128);
	}
	if (signal(SIGQUIT, sig_handler) == SIG_ERR)
	{
		ft_putstr_fd("fatal error\n", 2);
		exit(128);
	}
	loop();
}
