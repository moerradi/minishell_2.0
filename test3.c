#include "headers/minishell.h"

extern char	**environ;
int test();

int main(int ac, char **av)
{
	// printf("%s\n", env[0]);
	// free(env[0]);

putenv("znpo=g");
putenv("A=d");
test();


// perror("pi");
// while ("")
// char * t ;
// t = NULL;
// perror("t");
// printf("zn: %s\n", getenv("znpo"));
}