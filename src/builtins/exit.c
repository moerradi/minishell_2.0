/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:01:26 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/07 22:21:58 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	exit_err(char *arg)
{
	ft_putstr_fd("bash: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	return (2);
}

bool	ft_isnumeric(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (false);
	return (true);
}

int	bash_exit(char **args, int ac)
{
	ft_putendl_fd("exit", 2);
	if (ac == 0)
		exit(0);
	if (ac >= 1)
	{
		if (!ft_isnumeric(args[0]))
			exit(exit_err(args[0]));
		else if (ac == 1)
			exit(ft_atoi(args[0]));
		else
		{
			ft_putstr_fd("bash: exit: too many arguments\n", 2);
			return (2);
		}
	}
	return (0);
}
