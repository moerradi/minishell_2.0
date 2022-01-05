/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:08:59 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/04 00:36:36 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	mdict_print(t_dict *dict)
{
	while (dict != NULL)
	{
		printf("%s=%s\n", dict->key, dict->value);
		dict = dict->next;
	}
}

char	*mdict_key_search(t_dict *dict, char *key)
{
	while (dict != NULL)
	{
		if (!ft_strcmp(dict->key, key))
			return (dict->value);
		dict = dict->next;
	}
	return (NULL);
}

t_dict	*mdict_node_search(t_dict *dict, char *key)
{
	while (dict != NULL)
	{
		if (!ft_strcmp(dict->key, key))
			return (dict);
		dict = dict->next;
	}
	return (NULL);
}

void	mdict_change_value(t_dict **dict, char *key, char *value)
{
	t_dict	*tmp;

	tmp = *dict;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			return ;
		}
	}
}
