/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:07:46 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/07 22:29:05 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_dict	*g_env;

char	**splitby(char* str, char delim)
{
	int		i;
	int		len;
	t_list	*tmp;
	t_list	*node;

	tmp = NULL;
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == delim)
		{
			while (str[i] != ' ' && str[i] != delim)
			ft_lstnew();
		}
	}
}

char	*expand(char *key)
{
	char *out;

	out = mdict_key_search(g_env, key);
	if (!out)
		return ("");
	return (out);
}

char	**lst_to_arr(t_list	*lst, size_t size)
{
	t_list	*tmp;
	char	**out;
	int		i;

	tmp = lst;
	out = (char **)malloc(sizeof(char*) * (size + 1));
	i = 0;
	while(tmp)
	{
		out[i++] = ft_strdup((char *)tmp->content);
		tmp = tmp->next;
	}
	out[i] = NULL;
	return (out);
}

int		str_alnum(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '=')
			return (1);
		i++;
	}
	return (0);
}

