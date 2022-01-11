/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:07:02 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/11 05:01:24 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	set_exit(int status)
{
	char	*toput;
	char	*num;

	num = ft_itoa(status);
	toput = ft_strjoin("?=", num);
	free(num);
	ft_putenv(toput);
	free(toput);
}

int		ret_error(char *str, int ret)
{
		ft_putendl_fd(str, 2);
		return (ret);
}

int	get_status(int status)
{
	int	ret;
	if (WIFEXITED(status))
	{
		ret = WEXITSTATUS(status);
	}
		
	if (WIFSIGNALED(status))
	{
		ret = WTERMSIG(status);
		if (ret != 131)
			ret += 128;
	}
	return (ret);
}

int is_dir(const char *path)
{
   struct stat statbuf;

   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}