#include "headers/minishell.h"


void	sigaction_handler(int sig, siginfo_t *info, void* ucontext)
{
	if (sig == SIGINT)
	{
		kill(info->si_pid, SIGINT);
	}
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
	if (pid == 0)
	{
		sig.sa_flags = SA_SIGINFO;
		sig.sa_sigaction = sigaction_handler;
		if (sigaction(SIGINT, &sig, NULL) == -1)
		{
			ft_putstr_fd("fatal error\n", 2);
			exit(125);
		}
		while (1){}
	}
	else
	{
		waitpid(pid, 0, 0);
		printf("\ndone\n");
		while(1);
	}
}