/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:41:48 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/12/16 14:12:47 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_dict	*g_env;

void	print_export(void)
{
	t_dict	*dict;

	dict = g_env;
	while (dict != NULL)
	{
		if (!ft_strcmp(dict->value, ""))
			printf("%s='%s'\n", dict->key, dict->value);
		dict = dict->next;
	}
}

int	export(char **args, int ac)
{
	if (ac == 0)
		print_export();
	return (0);
}
