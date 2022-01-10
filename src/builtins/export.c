/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:41:48 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/10 11:46:26 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	export_error(char *av)
{
	ft_putstr_fd("3lash: export: '", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("' :not a valid identifier\n", 2);
	return (1);
}

void	print_export(int fd[2])
{
	int	i;
	int	j;

	i = 0;
	dup2(fd[1], 1);
	while (g_env[i])
	{
		if (ft_strncmp(g_env[i], "?=", 2))
			continue ;
		j = 0;
		while (g_env[i][j] != '=' && g_env[i][j])
			printf("%c", g_env[i][j++]);
		printf("=\"%s\"\n", ft_strchr(g_env[i], '=') + 1);
		i++;
	}
	close(fd[0]);
	close(fd[1]);
	exit(0);
}

void	sort_it(int fd[2], int out)
{
	char **args;

	args = ft_split("sort ", ' ');
	dup2(fd[0], 0);
	dup2(out, 1);
	close(fd[0]);
	close(fd[1]);
	ft_execvp("sort", args);
}

int	sort_export(int out)
{
	int		fd[2];
	int		pid;
	int		id;

	if (pipe(fd) == -1)
		return (ret_error("FATAL ERROR", 1));
	pid = fork();
	if (pid < 0)
		return(ret_error("FATAL ERROR", 1));
	if (pid == 0)
		print_export(fd);
	else
	{
		waitpid(pid, NULL, 0);
		id = fork();
		if (id < 0)
			return(ret_error("FATAL ERROR", 1));
		if (id == 0)
			sort_it(fd, out);
		close(fd[0]);
		close(fd[1]);
		waitpid(id, NULL, 0);
	}
}

int	export(char **args, int ac, int fd)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	if (ac == 0)
		sort_export(fd);
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
