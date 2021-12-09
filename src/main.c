#include "minishell.h"
#include <stdlib.h>

void	print_arrow(bool isred)
{
	if (isred)
		printf("\033[0;31m➜\033[0m  ");
	else
		printf("\033[0;32m➜\033[0m  ");

}

t_cmd	parse_cmd(char	*command)
{

}

void	run_cmd(t_cmd cmd)
{}

char	*prompt(void)
{
	char	*cwd;
	char	buf[4097];
	char	*prompt_msg;
	char	*raw_cmd;

	cwd = getcwd(buf, 4096);
	raw_cmd = readline(ft_strrchr(cwd, '/') + 1);

	return (raw_cmd);
}

int		main()
{
	char	*raw_cmd;
	t_cmd	parsed_cmd;

	//set up environment varibales as a global variable 
	set_envs();

	// prompt infinite loop
	while (1)
	{
		// get command
		raw_cmd = prompt();
		// store it in hostory
		if (raw_cmd && *raw_cmd)
			add_history(raw_cmd);
		// parse command
		parsed_cmd = parse_cmd(raw_cmd);
		
		run_cmd(parsed_cmd);
		post_cmd_clenup(raw_cmd, parsed_cmd);
	}
}