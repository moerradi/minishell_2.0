/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 05:30:10 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/04 05:32:07 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int		export_error(char *av) // dup and use printf;
{
	ft_putstr_fd("3lash: export: '", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("' :not a valid identifier\n", 2);
}

void	print_export(int fd) // same here
{
	t_dict	*dict;

	dict = g_env;
	while (dict != NULL)
	{
		if (dict->value == NULL)
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
		dict = dict->next;
	}
}