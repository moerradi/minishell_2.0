#include "../headers/minishell.h"

t_dict	*g_env;

void	print_arrow(bool isred)
{
	if (isred)
		printf("\033[0;31m➜\033[0m  ");
	else
		printf("\033[0;32m➜\033[0m  ");
}

int		get_last_exit_code()
{
	return (0);
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

int		main(int argc, char **argv, char **environ)
{
	char	*raw_line;
	char	*tmp;
	t_list	*pipes;

	g_env = mdict_fill(environ);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	while (1)
	{
		tmp = prompt();
		raw_line = ft_strtrim(tmp, " \t");
		if (!tmp)
			exit(0);
		if (!(*raw_line))
			continue;
		add_history(tmp);
		pipes = parse(raw_line);
		if (!pipes)
		{
			printf("Parse error\n");
			continue;
		}
		ft_lstiter(pipes, &deb_print_pipe);
		free(raw_line);
		run_cmd(pipes);
		ft_lstclear(&pipes, &free_pipe);
	}
}