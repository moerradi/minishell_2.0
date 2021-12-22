#include "../headers/minishell.h"

t_dict	*g_env;

void	print_arrow(bool isred)
{
	if (isred)
		printf("\033[0;31m➜\033[0m  ");
	else
		printf("\033[0;32m➜\033[0m  ");
}

// char	*ms_get_env(char *var)
// {

// }
int		get_last_exit_code()
{
	return (0);
	// return (ft_atoi(ms_get_env("?")));
}



char	**parse_cmd(char *cmd)
{
	char **out;
	char *tmp;

	out = NULL;
	tmp = parse_quotes(cmd);
	if (tmp)
	{
		out = split_pipes(tmp);
		free(tmp);
	}
	return (out);
}

void	run_cmd(t_list *cmd)
{}

char	*prompt(void)
{
	char	*cwd;
	char	*prompt_msg;
	char	*raw_cmd;

	cwd = getcwd(NULL, 4096);
	prompt_msg = ft_strrchr(cwd, '/') + 1;
	prompt_msg = ft_strjoin(prompt_msg, " > ");
	raw_cmd = readline(prompt_msg);
	free(cwd);
	free(prompt_msg);
	return (raw_cmd);
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
	char	*raw_cmd;
	char	*tmp;
	t_list	*parsed_cmd;
	char	**pipes;

	//set up environment varibales as a global variable
	g_env = mdict_fill(environ);
	// parse_env(vars);

	// prompt infinite loop
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	while (1)
	{
		// get command
		tmp = prompt();
		raw_cmd = ft_strtrim(tmp, " \t");
		// // store it in hostory
		if (!tmp)
			exit(0);
		if (!(*raw_cmd))
			continue;
		add_history(tmp);
		// parse command
		pipes = parse_cmd(raw_cmd);
		if (!pipes)
		{
			printf("Syntax error\n");
			continue;
		}
		print_pipes(pipes);
		free(raw_cmd);
		raw_cmd = NULL;
		run_cmd(parsed_cmd);
		// post_cmd_clenup(raw_cmd, parsed_cmd);
	}
}