#include "headers/minishell.h"

int main()
{
	t_pipe *pipes;

	pipes = malloc(sizeof(t_pipe) * 6);
	pipes[0].args = ft_split("Hello world", " ");
	pipes[0].input_file = NULL;
	pipes[0].output_file = NULL;
	pipes[0].command = ft_strdup("echo");
}