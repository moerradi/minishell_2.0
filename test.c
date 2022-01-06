/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 04:39:16 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/04 05:19:19 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"


void	sigaction_handler(int sig, siginfo_t *info, void* ucontext)
{
	if (sig == SIGINT)
		kill(info->si_pid, SIGINT);
}

void handler(int te)
{
	printf("\n");
}

int	main(int ac, char **argv, char **envp)
{
	pid_t pid;
	signal(SIGINT, handler);
	struct sigaction sig;
	pid = fork();
	waitpid(pid, 0, 0);
	if (pid == 0)
	{
		sig.sa_flags = SA_SIGINFO;
		sig.sa_sigaction = sigaction_handler;
		if (sigaction(SIGUSR1, &sig, NULL) == -1)
		{
			ft_putstr_fd("fatal error.", 2);
			exit(1);
		}
		execve("/bin/cat", argv, envp);
	}
	else
	{
		printf("\ndone\n");
		while(1);
	}
}
