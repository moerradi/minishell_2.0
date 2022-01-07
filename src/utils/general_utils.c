/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:07:46 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/07 20:03:39 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int		toklen(char const *str, char c)
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
		len = 0;
		if (str[start] == c)
			while (str[start + len] == c && str[start + len])
				len++;
		else
			while (str[start + len] != c && str[start + len])
				len++;
		out[i] = ft_substr(str, start, len);
		if (!out[i++])
			return (ft_garbage(&out, i - 1));
		start += len;		
	}
	out[i] = NULL;
	return (out);
}

char	*expand_str(char *str)
{
	char	**tokens;
	char	*out;
	char	*tmp;
	int		i;

	tokens = adv_split(str, -32);
	out = NULL;
	tmp = NULL;
	i = 0;
	while (tokens[i])
	{
		if (ft_strchr(tokens[i], '$'))
			tmp = ft_strjoin(out, expand(tokens[i]));
		else
			tmp = ft_strjoin(out, tokens[i]);
		free(out);
		out = tmp;
		i++;
	}
	free_strs(tokens);
	return (out);
}

char	*expand(char *str)
{
	int		i;
	char	*out;
	char	**toks;
	char	*tmp;

	toks = ft_strtok(str, "$");
	tmp = NULL;
	out = NULL;
	i = 0;
	while (toks[i])
	{
		if (!ft_strcmp(toks[i], "$") && toks[i + 1] && *toks[i + 1] > 0)
			tmp = ft_strjoin(out, getenv(toks[++i]));
		else
			tmp = ft_strjoin(out, toks[i]);
		free(out);
		out = tmp;
		i++;
	}
	free_strs(toks);
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
