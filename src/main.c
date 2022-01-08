#include "../headers/minishell.h"

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

int	main(int argc, char **argv, char **environ)
{
	char	*raw_line;
	char	*tmp;
	t_list	*pipes;

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
		add_history(tmp);
		pipes = parse(raw_line);
		free(raw_line);
		free(tmp);
		if (!pipes)
			printf("Parse error\n");
		ft_lstiter(pipes, &deb_print_pipe);
		int id = fork();
		run_cmd(pipes);
		ft_lstclear(&pipes, &free_pipe);
	}
}
