/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:55:52 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/09 22:06:34 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	pwd(int args_count)
{
	char	*cwd;
	int		err_tmp;

	if (args_count == 0)
	{
		cwd = getcwd(NULL, 4096);
		if (cwd == NULL)
		{
			err_tmp = errno;
			ft_putstr_fd("pwd: ", 2);
			ft_putstr_fd(strerror(err_tmp), 2);
			ft_putstr_fd("\n", 2);
		}
		else
		{
			printf("%s\n", cwd);
			free(cwd);
		}
	}
	else
		ft_putstr_fd("pwd: too many arguments\n", 2);
	return (0);
}
