/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:08:59 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/12/15 20:36:38 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	mdict_print(t_dict *dict)
{
	while (dict != NULL)
	{
		printf("%s = %s\n", dict->key, dict->value);
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
	t_dict *tmp;

	tmp = *dict;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			tmp->value = value;
			return;
		}
	}
}
// void	mdict_remove(t_dict **dict, char *key)
// {
// 	t_dict *tmp;
// 	t_dict *next;
// 	t_dict *prev;

// 	tmp = *dict;
// 	prev = *dict;
// 	while (tmp != NULL)
// 	{
// 		next = tmp->next;
// 		if (!ft_strcmp(tmp->key, key))
// 		{
// 			if (prev == *dict)
// 				*dict = (*dict)->next;
// 			else
// 				prev->next = next;
// 			mdict_delone(&tmp);
// 			return;
// 		}
// 		prev = tmp;
// 		tmp = tmp->next;
// 	}
// }
// int main(int ac, char **av, char **env)
// {
// 	t_dict *dict;

// 	dict = mdict_fill(env);
// 	mdict_remove(&dict, av[1]);
// 	mdict_print(dict);
// }