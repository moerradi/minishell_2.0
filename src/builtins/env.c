/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:52:04 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/09 20:14:56 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	env(int fd)
{
	int	i;

	i = 0;
	while (g_env[i])
	{
		if (ft_strncmp(g_env[i], "?=", 2))
		{
			ft_putstr_fd(g_env[i], fd);
			ft_putstr_fd("\n", fd);
		}
		i++;
	}
	return (0);
}
