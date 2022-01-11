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

char	**g_env;

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

void	sig_handler(int sig, siginfo_t *info, void* ucontext)
{
	(void)ucontext;
	if (sig == SIGINT)
	{
		if (info->si_pid != 0)
		{
			set_exit(130);
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		else
			kill(0, SIGINT);
	}
	else if (sig == SIGQUIT)
	{
		if (info->si_pid != 0)
		{
			if (!ft_strcmp(rl_line_buffer, ""))
				exit(131);
		}
		else
			kill(0, SIGQUIT);
	}
}
void	loop()
{
	char	*raw_line;
	char	*tmp;
	t_list	*pipes;

	while (1)
	{
		tmp = prompt();
		raw_line = ft_strtrim(tmp, " \t");
		if (!tmp)
			exit(0);
		if (*raw_line)
			pipes = parse(raw_line);
		if (!pipes && *raw_line)
			ft_putstr_fd("Parse error !\n", 2);
		free(raw_line);
		add_history(tmp);
		free(tmp);
		run_cmd(pipes);
		ft_lstclear(&pipes, &free_pipe);
	}
}
int	main(int argc, char **argv, char **envir)
{
	struct sigaction sig;

	(void)argc;
	(void)argv;
	ascii_art();
	init_environ(envir);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = sig_handler;
	if (sigaction(SIGINT, &sig, NULL) == -1)
	{
		ft_putstr_fd("fatal error\n", 2);
		exit(128);
	}
	if (sigaction(SIGQUIT, &sig, NULL) == -1)
	{
		ft_putstr_fd("fatal error\n", 2);
		exit(128);
	}
	loop();
}
