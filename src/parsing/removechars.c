/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removechars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:01:22 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/01 17:13:36 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	count_chars_less(char	*str, const char *charset)
{
	int	i;
	int	oc;

	i = 0;
	oc = 0;
	while (str[i])
	{
		if (ft_strchr(charset, str[i]))
			oc++;
		i++;
	}
	return (i - oc);
}

char	*removechars(char *str, const char *charset)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	out = malloc(sizeof(char) * (count_chars_less(str, charset) + 1));
	if (!out)
		return (NULL);
	while (str[i])
	{
		if (!ft_strchr(charset, str[i]))
		{
			out[j] = str[i];
			j++;
		}
		i++;
	}
	out[j] = '\0';
	return (out);
}
