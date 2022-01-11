/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:09:08 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/06 23:51:16 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	unset_error(char *av)
{
	ft_putstr_fd("3lash: unset: '", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("' :not a valid identifier\n", 2);
	return (1);
}

void	unset_one(char *arg)
{
	int		len;
	char	**ptr;
	int		i;

	len = ft_strlen(arg);
	i = 0;
	while (g_env[i])
	{
		if (!ft_strncmp(g_env[i], arg, len) && g_env[i][len] == '=')
		{
			ptr = &g_env[i];
			while (*ptr)
			{
				ptr[0] = ptr[1];
				ptr++;
			}
		}
		i++;
	}
}

int	is_str_alnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	unset(char **args)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	while (args[i] != NULL)
	{
		if (!ft_isalpha(args[i][0]))
			out = unset_error(args[i]);
		else if (is_str_alnum(args[i]))
			out = unset_error(args[i]);
		else if (ft_strchr(args[i], '='))
			unset_one(args[i++]);
		i++;
	}
	return (out);
}
