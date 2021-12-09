/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:43:09 by moerradi          #+#    #+#             */
/*   Updated: 2019/10/09 17:51:36 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*tempsrc;
	unsigned char		*tempdst;
	size_t				i;

	if (src == dst)
		return (dst);
	tempsrc = (unsigned char *)src;
	tempdst = (unsigned char *)dst;
	if (src == NULL && dst == NULL)
		return (NULL);
	i = 1;
	if (dst > src)
	{
		while (i <= len)
		{
			tempdst[len - i] = tempsrc[len - i];
			i++;
		}
	}
	else
	{
		while (len--)
			*(tempdst++) = *(tempsrc++);
	}
	return (dst);
}
