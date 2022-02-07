#include "./headers/minishell.h"

char	**g_env;

int main()
{
	run_cmd(parse("/bin/cat | /bin/ls"));
}