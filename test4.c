#include "headers/minishell.h"

extern char **environ;

// // int	ft_putenv(const char *string)
// // {
// // 	static char	**last_env = NULL;
// // 	char	**ep;
// // 	char	**new_env;
// // 	size_t	namelen;
// // 	size_t	size;
// // 	char	*name;

// // 	name = ft_strndup(string, ft_strchr(string, '=') - string);
// // 	namelen = ft_strlen(name);
// // 	ep = environ;
// // 	size = 0;
// // 	while (*ep != NULL)
// // 	{
// // 		if (!strncmp (*ep, name, namelen) && (*ep)[namelen] == '=')
// // 			break;
// // 		else
// // 			size++;
// // 		++ep;
// // 	}
// // 	if (*ep == NULL)
// // 	{
// // 		new_env = (char **) malloc(sizeof(char *) * (size + 2));
// // 		if (last_env)
// // 		{
// // 			ft_memcpy((char *) new_env, (char *) last_env, size * sizeof (char *));
// // 			free(last_env);
// // 		}
// // 		else
// // 			ft_memcpy((char *) new_env, (char *) environ, size * sizeof (char *));
// // 		new_env[size] = NULL;
// // 		new_env[size + 1] = NULL;
// // 		ep = new_env + size;
// // 		environ = new_env;
// // 		last_env = environ;
// // 	}
// // 	free(name);
// // 	char *np;
// // 	np = (char *) string;
// // 	*ep = np;
// // 	return 0;
// // }

int test()
{

	ft_putenv("ww=wwsa");

	ft_putenv("sassa=sas");
	ft_putenv("kalshaaaaa=lmknessi");
	ft_putenv("t7richa=layrzini");
	ft_putenv("sassa=kalsha");
	ft_putenv("lili=yahlili");
	ft_putenv("s=k");

	int i = 0;
	while (environ[i])
	printf(" %s\n", environ[i++]);
		// i++;
// __add_to_environ("HELLO", NULL,"HELLO=ZZS",1);
// __add_to_environ("Mello", NULL,"Mello=ZZS",1);




}