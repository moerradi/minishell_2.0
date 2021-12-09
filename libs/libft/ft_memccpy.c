/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:01:36 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/01 16:54:36 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*tempsrc;
	unsigned char		*tempdst;

	i = 0;
	tempsrc = (unsigned char *)src;
	tempdst = (unsigned char *)dst;
	while (i < n)
	{
		*tempdst = *tempsrc;
		if (*tempdst == (unsigned char)c)
			return (tempdst + 1);
		tempdst++;
		tempsrc++;
		i++;
	}
	return (NULL);
}
