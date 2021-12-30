/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 02:07:40 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/12/21 04:10:17 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	space_len(char *str, char *set)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(set, str[i]) && str[i] == str[i + 1])
		{
			len = len + 3;
			i++;
		}
		else if (ft_strchr(set, str[i]))
			len = len + 2;
		i++;
		len++;
	}
	return (len);
}

char	*spacify(char *str, char *set, int len)
{
	char	*out;
	int		i;
	int		j;

	j = 0;
	i = 0;
	out = malloc(sizeof(char) * len);
	while (i < len)
	{
		if (ft_strchr(set, str[j]) && str[j] == str[j + 1])
		{
			out[i++] = ' ';
			out[i++] = str[j++];
			out[i++] = str[j++];
			out[i++] = ' ';
		}
		else if (ft_strchr(set, str[j]))
		{
			out[i++] = ' ';
			out[i++] = str[j++];
			out[i++] = ' ';
		}
		else
			out[i++] = str[j++];
	}
	out[i] = '\0';
	return (out);
}

char	**ft_strtok(char *str, char *set)
{
	char	*spaced;
	char	**out;
	int		len;

	len = space_len(str, set);
	spaced = spacify(str, set, len);
	out = ft_split (spaced, ' ');
	free(spaced);
	return (out);
}
