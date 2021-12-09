/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 02:27:47 by moerradi          #+#    #+#             */
/*   Updated: 2019/10/11 21:54:28 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*tempdst;
	const char	*tempsrc;
	size_t		n;
	size_t		dlen;

	tempdst = dst;
	tempsrc = src;
	n = size;
	while (n-- && *tempdst)
		tempdst++;
	dlen = tempdst - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(tempsrc));
	while (*tempsrc)
	{
		if (n != 1)
		{
			*tempdst++ = *tempsrc;
			n--;
		}
		tempsrc++;
	}
	*tempdst = '\0';
	return (dlen + (tempsrc - src));
}
