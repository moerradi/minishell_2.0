/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:41:48 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/04 22:12:01 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_dict	*g_env;

void	sort_export(void)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	char **args; 
	
	args = malloc(sizeof(char *) * 2);
	args[0] = "sort";
	args[1] = NULL;
	if (pipe(fd) == -1)
		return;
	pid1 = fork();// add check pid <0
	if (pid1 == 0)
	{
		dup2(fd[1], 1);
		env();
		close(fd[1]);
	}
	pid2 = fork(); //add check pid < 0;
	if (pid2 == 0)
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		ft_execvp("sort", args, NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	export(char **args, int ac)
{
	int i;
	
	i = 0;
	if (ac == 0)
		sort_export();
	else
	{
		while (args[i] != NULL)
		{
			if (!ft_isalpha(args[i][0]))
				export_error(args[i]);
			else
				putenv(args[i]);
			i++;
		}
	}
	return (0);
}

// char	**mini_split(char *av, char c)
// {
// 	char **out;
// 	int		i;

// 	i = 0;
// 	out = malloc(sizeof(char *) * 3);
// 	while (av[i] && av[i] != c)
// 		i++;
// 	out[0] = ft_substr(av, 0, i++);
// 	if ((ft_strlen(av) - i) == 0)
// 		out[1] = ft_strdup("");
// 	else
// 		out[1] = ft_substr(av, i,ft_strlen(av) - i );
// 	out[2] = NULL;
// 	return (out);
// }

// int		main(int	ac, char **av, char **environ)
// {
// 	char **out;
// 	int	i;

// 	i = 0;
// 	while (av[i] != NULL)
// 		i++;
// 	g_env = mdict_fill(environ);
// 	export(++av, i - 1);
// }
