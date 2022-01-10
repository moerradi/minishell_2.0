/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:20:30 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/09 20:13:40 by kdrissi-         ###   ########.fr       */
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
	while (!ft_strcmp(args[i], "-n"))
		i++;
	while (i < ac - 1)
	{
		ft_putstr_fd(args[i++], fd);
		ft_putstr_fd(" ", fd);
	}
	ft_putstr_fd(args[i], fd);
	if (ft_strcmp(args[0], "-n"))
		ft_putstr_fd("\n", fd);
	return (0);
}
