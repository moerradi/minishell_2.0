/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:52:04 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/12/16 14:11:06 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_dict	*g_env;

int	env(void)
{
	t_dict	*dict;

	dict = g_env;
	while (dict != NULL)
	{
		printf("%s=%s\n", dict->key, dict->value);
		dict = dict->next;
	}
	return (0);
}
