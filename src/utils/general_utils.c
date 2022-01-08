/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:07:46 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/08 09:35:35 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	toklen(char const *str, char c)
{
	int		len;
	bool	st;

	st = true;
	len = 0;
	while (*str)
	{
		if (*str == c)
		{
			st = true;
			while (*str == c && *str)
				str++;
			len++;
			if (!(*str))
				break ;
		}
		if (st)
		{
			st = false;
			len++;
		}
		str++;
	}
	return (len);
}

static int	calc_len(char *str, char c, int start)
{
	int	len;

	len = 0;
	if (str[start] == c)
		while (str[start + len] == c && str[start + len])
			len++;
	else
		while (str[start + len] != c && str[start + len])
			len++;
	return (len);
}

char	**adv_split(char *str, char c)
{
	char	**out;
	int		i;
	int		tc;
	int		start;
	int		len;

	tc = toklen(str, c);
	out = (char **)malloc(sizeof(char *) * (tc + 1));
	i = 0;
	start = 0;
	while (i < tc)
	{
		len = calc_len(str, c, start);
		out[i] = ft_substr(str, start, len);
		if (!out[i++])
			return (ft_garbage(&out, i - 1));
		start += len;
	}
	out[i] = NULL;
	return (out);
}

char	**lst_to_arr(t_list	*lst, size_t size)
{
	t_list	*tmp;
	char	**out;
	int		i;

	tmp = lst;
	out = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (tmp)
	{
		out[i++] = ft_strdup((char *)tmp->content);
		tmp = tmp->next;
	}
	out[i] = NULL;
	return (out);
}

int	str_alnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '=')
			return (1);
		i++;
	}
	return (0);
}
