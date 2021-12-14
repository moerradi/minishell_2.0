/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:32:47 by moerradi          #+#    #+#             */
/*   Updated: 2021/12/11 17:45:48 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int		cd(char **args, int args_count)
{
	int	err_tmp;

	//if (args_count == 0)
		// cwd $HOME
	/*else*/ if (args_count == 1)
	{
		if(chdir(args[0]) == -1)
		{
			err_tmp = errno;
			printf("cd: %s: %s\n", args[0], strerror(err_tmp));
		}
		return (0);
	}
	else
	{
		printf("cd: too many arguments\n");
		return (0);
	}
}