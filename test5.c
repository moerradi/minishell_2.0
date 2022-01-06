#include <string.h>
#include <stdio.h>

int main()
{
	char * str = strdup("Hello     world thid id");
	char *s;
	s = strtok(str, " ");
	printf("%s\n", s);
	while (s = (strtok(NULL, " ")))
		printf("%s\n", s);
}