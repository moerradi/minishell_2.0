/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:37:41 by moerradi          #+#    #+#             */
/*   Updated: 2019/10/09 12:17:34 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tempsrc;
	unsigned char	*tempdst;

	if (src == NULL && dst == NULL)
		return (NULL);
	tempsrc = (unsigned char *)src;
	tempdst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*tempdst++ = *tempsrc++;
		i++;
	}
	return (dst);
}
