/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_rep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:20:50 by moerradi          #+#    #+#             */
/*   Updated: 2021/12/18 16:42:47 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_rep(char const *s, char c, int rep)
{
	char			**out;
	int				i;
	unsigned int	start;
	size_t			len;

	i = 0;
	start = 0;
	out = malloc(sizeof(char *) * (rep + 1));
	if (s == NULL || !out)
		return (NULL);
	while (i < rep)
	{
		while (s[start] && s[start] == c)
			start++;
		if (i == rep - 1)
			len = count_len(s, start, '\0');
		else
			len = count_len(s, start, c);
		out[i] = ft_substr(s, start, len);
		if (!out[i++])
			return (ft_garbage(&out, i - 1));
		start += len;
	}
	out[i] = NULL;
	return (out);
}

int	count_len(char const *s, int start, char c)
{
	int	len;

	len = 0;
	if (!c)
		while (s[len + start])
			len++;
	if (c)
		while (s[len + start] && s[len + start] != c)
			len++;
	return (len);
}

void	free_arr(char ***arr)
{
	char	**tmp;

	tmp = *arr;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(*arr);
	*arr = NULL;
}
