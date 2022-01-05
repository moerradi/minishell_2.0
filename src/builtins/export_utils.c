/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 05:30:10 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/04 22:16:29 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

extern char	**environ;

int		export_error(char *av) // dup and use printf;
{
	ft_putstr_fd("3lash: export: '", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("' :not a valid identifier\n", 2);
}

void	print_export(int fd) // same here
{
	int i;
	char **split;

	i = 0;
	
	while (environ[i] != NULL)
	{
		if (ft_strchr())
		{
			ft_putstr_fd(dict->key, fd);
			ft_putstr_fd("\n",fd);
		}
		else
		{
			ft_putstr_fd(dict->key, fd);
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(dict->value, fd);
			ft_putstr_fd("\"\n",fd);
		}
		i++;
	}
}

int ft_putenv(const char *string)
{
	char	**ep;
	size_t	namelen;
	char	*name;
	char	*np;

    name = ft_strndup(string, ft_strchr(string, '=') - string);
    namelen = ft_strlen(name);
    ep = environ;
	while (ep != NULL)
	{
		if (!ft_strncmp (ep, name, namelen) && (ep)[namelen] == '=')
			break;
		++ep;
	}
	free(name);
	np = (char *) string;
	*ep = np;
	return 0;
}
