/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:51:41 by moerradi          #+#    #+#             */
/*   Updated: 2019/10/09 23:43:50 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*out;
	unsigned int	start;
	size_t			len;

	start = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1) - 1;
	while (is_inset(s1[start], set) && s1[start])
		start++;
	while (is_inset(s1[len], set) && len > 0)
		len--;
	len++;
	len -= start;
	out = ft_substr(s1, start, len);
	if (!out)
		return (NULL);
	return (out);
}
