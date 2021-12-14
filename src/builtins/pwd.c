/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:55:52 by moerradi          #+#    #+#             */
/*   Updated: 2021/12/12 14:44:33 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int	pwd(char **args, int args_count)
{
	char	*cwd;
	int		err_tmp;

	if (args_count == 1)
	{
		cwd = getcwd(4096, NULL);
		if (cwd == NULL)
		{
			err_tmp = errno;
			printf("pwd: %s\n", strerror(err_tmp));
		}
		printf("%s\n", cwd);
	}
	else
	{
		// replace with with printing to stderror
		printf("pwd: too many arguments\n");
	}
}