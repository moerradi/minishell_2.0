#include "../headers/minishell.h"


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



t_list	*parse_cmd(char	*command)
{

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
	raw_cmd = readline(prompt_msg);
	free(cwd);
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

int		main(int argc, char **argv)
{
	char	*raw_cmd;
	t_list	*parsed_cmd;

	//set up environment varibales as a global variable 
	// parse_env(vars);

	// prompt infinite loop
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	while (1)
	{
		// get command
		raw_cmd = prompt();
		// // store it in hostory
		if (raw_cmd == NULL)
			exit(0);
		if (raw_cmd && *raw_cmd)
			add_history(raw_cmd);
		// parse command
		parsed_cmd = parse_cmd(raw_cmd);
		free(raw_cmd);
		raw_cmd = NULL;
		run_cmd(parsed_cmd);
		// post_cmd_clenup(raw_cmd, parsed_cmd);
	}
}