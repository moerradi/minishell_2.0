/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:41:48 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/07 04:32:47 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

extern char	**environ;

void	print_export(int fd[2])
{
	int	i;
	int	j;

	i = 0;
	dup2(fd[1], 1);
	while (environ[i])
	{
		j = 0;
		while (environ[i][j] != '=' && environ[i][j])
			printf("%c", environ[i][j++]);
		printf("=\"%s\"\n", ft_strchr(environ[i], '=') + 1);
		i++;
	}
	close(fd[0]);
	close(fd[1]);
	exit(0);
}

int	export_error(char *av)
{
	ft_putstr_fd("3lash: export: '", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("' :not a valid identifier\n", 2);
	return (1);
}

void	sort_export(void)
{
	int		fd[2];
	int		pid;
	int		id;

	if (pipe(fd) == -1)
		//error ;
	pid = fork();
	if (pid < 0)
		//error;
	if (pid == 0)
		print_export(fd);
	else
	{
		waitpid(pid, NULL, 0);
		id = fork();
		if (id < 0)
			//error
		if (id == 0)
			sort_it(fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(id, NULL, 0);
	}
}

void	sort_it(int	fd[2])
{
	char **args;

	args = ft_split("sort ", ' ');
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	ft_execvp("sort", args);
}

int	export(char **args, int ac)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	if (ac == 0)
		sort_export();
	else
	{
		while (args[i] != NULL)
		{
			if (!ft_isalpha(args[i][0]))
				out = export_error(args[i]);
			else if (str_alnum(args[i]))
				out = export_error(args[i]);
			else if (ft_strchr(args[i], '='))
				ft_putenv(args[i]);
			i++;
		}
	}
	return (out);
}
