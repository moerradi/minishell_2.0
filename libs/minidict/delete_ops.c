/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:33:08 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/12/16 13:17:01 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	mdict_destroy(t_dict **dict)
{
	t_dict	*tmp;
	t_dict	*next;

	if (!dict)
		return ;
	tmp = *dict;
	while (tmp)
	{
		next = tmp->next;
		mdict_delone(&tmp);
		tmp = next;
	}
	*dict = NULL;
}

void	mdict_delone(t_dict **dict)
{
	free((*dict)->key);
	free((*dict)->value);
	free(*dict);
}

void	mdict_remove_node(t_dict **dict, char *key)
{
	t_dict	*tmp;
	t_dict	*hold;

	if (!ft_strcmp(tmp->key, key))
	{
		*dict = (*dict)->next;
		mdict_delone(&tmp);
		return ;
	}
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->next->key, key))
		{
			hold = tmp->next;
			tmp->next = tmp->next->next;
			mdict_delone(&hold);
			return ;
		}
		tmp = tmp->next;
	}
}
