/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:20:30 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/02/04 20:09:27 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	echo(char **args, int ac, int fd)
{
	int	i;

	i = 0;
	if (ac == 0)
	{
		ft_putchar_fd('\n', fd);
		return (0);
	}
	while (args[i] && !ft_strcmp(args[i], "-n"))
		i++;
	while (i < ac - 1)
	{
		ft_putstr_fd(args[i++], fd);
		ft_putstr_fd(" ", fd);
	}
	if (i != ac)
		ft_putstr_fd(args[i], fd);
	if (ft_strcmp(args[0], "-n"))
		ft_putstr_fd("\n", fd);
	return (0);
}
