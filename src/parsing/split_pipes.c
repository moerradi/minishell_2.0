/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:27:35 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/08 09:46:40 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

bool	is_all_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

static size_t	count_pipes(char *str)
{
	int		t;
	size_t	wc;

	t = 1;
	wc = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '|')
		{
			if (t == 1)
				return (0);
			t = 1;
		}
		else if (t == 1)
		{
			t = 0;
			wc++;
		}
		str++;
	}
	if (t == 1)
		return (0);
	return (wc);
}

char	**split_pipes(char *s)
{
	char			**out;
	size_t			i;
	unsigned int	start;
	size_t			len;
	size_t			pc;

	i = 0;
	start = 0;
	pc = count_pipes(s);
	if (pc == 0)
		return (NULL);
	out = malloc(sizeof(char *) * (pc + 1));
	while (i < pc)
	{
		len = 0;
		while (s[len + start] && s[len + start] != '|')
			len++;
		out[i] = ft_substr(s, start, len);
		if (out[i] == NULL || is_all_space(out[i]))
			return (ft_garbage(&out, i + 1));
		start += len + 1;
		i++;
	}
	out[i] = NULL;
	return (out);
}
