/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:54:33 by moerradi          #+#    #+#             */
/*   Updated: 2019/10/10 18:25:01 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static size_t	abs_size(int n)
{
	if (n > 0)
		return (n);
	else
		return (n * -1);
}

char	*ft_itoa(int n)
{
	char			*out;
	size_t			numlen;
	size_t			i;
	unsigned int	ntemp;

	ntemp = abs_size(n);
	i = 0;
	numlen = ft_numlen(n);
	out = malloc(sizeof(char) * (numlen + 1));
	if (!out)
		return (NULL);
	if (n >= 0)
		out[0] = '0';
	else
		out[0] = '-';
	while (ntemp)
	{
		out[numlen - i - 1] = (ntemp % 10) + '0';
		ntemp /= 10;
		i++;
	}
	out[numlen] = '\0';
	return (out);
}
