/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:41:48 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/05 23:14:34 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
extern char	**environ;

void	sort_export(void)
{
	int	fd[2];
	int	pid;
	int	pidd;
	char **args; 
	
	// args = ft_strdup("sort");
	args = malloc(sizeof(char *) * 2);
	args[0] = "sort";
	args[1] = NULL;
	if (pipe(fd) == -1)
		return;
	pid = fork();
	// if (pid == 0)
	// {
	// 	dup2(fd[1], STDOUT_FILENO);
	// 	close(fd[0]);
	// 	close(fd[1]);
	// 	env();
	// }
	// else if (pid != 0)
	// 	pidd = fork(); //add check pid < 0;
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		ft_execvp("sort", args, NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pidd, NULL, 0);
}


int		export_error(char *av)
{
	ft_putstr_fd("3lash: export: '", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("' :not a valid identifier\n", 2);
	return (1);
}

int		str_alnum(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '=')
			return (1);
	}
	return (0);
}

int	export(char **args, int ac)
{
	int i;
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
void	ft_execvp(char *cmd, char **args, char **env)
{
	char		**all_paths;
	char		*str;
	char		*path;
	char		*tmp;
	int			i;

	str = getenv("PATH");
	all_paths = ft_split(str, ':');
	i = 0;
	while (all_paths[i] != NULL)
	{
		tmp = ft_strjoin("/", cmd);
		path = ft_strjoin(all_paths[i], tmp);
		free(tmp);
		execve(path, args, env);
		free(path);
		i++;
	}
	// free_strs(all_paths);
	i = errno;
	ft_putstr_fd(strerror(i), 2);
}
int		main(int	ac, char **av, char **environ)
{
	export(++av, ac - 1);
}
