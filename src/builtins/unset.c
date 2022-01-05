/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:09:08 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/04 21:02:52 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

extern char	**environ;

int     unset_one(char *arg)
{
	int	len;
	char **ptr;
	int	i;

	len = ft_strlen(arg);
	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(environ[i],arg, len) && environ[i][len] == '=')
		{
			ptr = &environ[i];
			while (*ptr)
			{
				ptr[0] = ptr[1];
				ptr++;
			}
		}
		i++;
	}
}
void	unset(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		unset_one(args[i++]);
}
