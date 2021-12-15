/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:32:55 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/12/15 20:37:20 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	mdict_insert(t_dict **dict, char *key, char *value)
{
	t_dict	*new;

	new = mdict_new(key, value);
	mdict_addback(dict, new);
}

void	mdict_addback(t_dict **alst, t_dict *new)
{
	t_dict	*current;

	if (!alst)
		return ;
	current = *alst;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else
		*alst = new;
}

t_dict	*mdict_new(char *key, char *value)
{
	t_dict	*new;

	new = (t_dict *)malloc(sizeof(t_dict));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

t_dict	*mdict_fill(char **env)
{
	t_dict	*dict;
	char	**split;

	dict = NULL;
	while (*env)
	{
		split = ft_split_rep(*env, '=', 2);
		mdict_insert(&dict, split[0], split[1]);
		free_arr(&split);
		env++;
	}
	return (dict);
}