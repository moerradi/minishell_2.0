/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:20:50 by moerradi          #+#    #+#             */
/*   Updated: 2019/10/09 23:40:29 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	int		t;
	size_t	wc;

	t = 1;
	wc = 0;
	while (*str)
	{
		if (*str == c)
			t = 1;
		else if (t == 1)
		{
			t = 0;
			wc++;
		}
		str++;
	}
	return (wc);
}

static char	**ft_garbage(char ***s, size_t idx)
{
	char	**splitout;
	size_t	i;

	i = 0;
	splitout = *s;
	while (i < idx)
	{
		free(splitout[i]);
		i++;
	}
	free(splitout);
	splitout = NULL;
	return (splitout);
}

char	**ft_split(char const *s, char c)
{
	char			**out;
	size_t			i;
	unsigned int	start;
	size_t			len;

	i = 0;
	start = 0;
	out = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (s == NULL || !out)
		return (NULL);
	while (i < count_words(s, c))
	{
		while (s[start] && s[start] == c)
			start++;
		len = 0;
		while (s[len + start] && s[len + start] != c)
			len++;
		out[i] = ft_substr(s, start, len);
		if (!out[i++])
			return (ft_garbage(&out, i - 1));
		start += len;
	}
	out[i] = NULL;
	return (out);
}
