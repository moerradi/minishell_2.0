/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execvp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:43:51 by moerradi          #+#    #+#             */
/*   Updated: 2022/02/05 19:53:59 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_execvp(char *cmd, char **args)
{
	char		**all_paths;
	char		*str;
	char		*path;
	char		*tmp;
	int			i;

	if (ft_strchr(cmd, '/'))
		return (execve(cmd, args, g_env));
	str = ft_getenv("PATH");
	all_paths = ft_split(str, ':');
	i = 0;
	while (all_paths[i])
	{
		tmp = ft_strjoin("/", cmd);
		path = ft_strjoin(all_paths[i], tmp);
		free(tmp);
		free(all_paths[i]);
		execve(path, args, g_env + 3);
		free(path);
		i++;
	}
	free(all_paths);
	return (-1);
}
