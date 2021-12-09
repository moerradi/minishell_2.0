/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:11:11 by moerradi          #+#    #+#             */
/*   Updated: 2019/10/09 23:54:14 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_validate(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && s[i + start])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	size;

	if (!s || (size_t)start > ft_strlen(s))
	{
		out = malloc(sizeof(char) * 1);
		if (!out)
			return (NULL);
		*out = '\0';
		return (out);
	}
	size = size_validate(s, start, len);
	out = malloc(sizeof(char) * (size + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < size)
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
