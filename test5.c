#include "./headers/minishell.h"



int main(int ac, char **av)
{
	char **ss = adv_split(av[1], ' ');
	deb_print_strarr(ss);
	// printf("%i\n", toklen(av[1], ' '));
}