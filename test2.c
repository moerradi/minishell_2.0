#include <string.h>
#include <stdio.h>

extern char **environ;

void	test()
{
	int i = 0;
	while(environ[i])
		printf("%s\n", environ[i++]);
	
}