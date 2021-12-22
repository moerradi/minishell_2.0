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
	int	j;

	i = 0;
	j = 0;
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

char	*spacify(char *str, char *set)
{
	char	*out;
	int		i;
	int		j;
	int		len;

	len = space_len(str, set);
	j = 0;
	i = 0;
	out = malloc(sizeof(char) * len);
	while (i < len)
	{
		if (ft_strchr(set, str[j]) && str[j] == str[j + 1])
		{
			out[i++] = ' ';
			out[i++] = str[j++];
			out[i++] = str[j];
			out[i] = ' ';
		}
		else if (ft_strchr(set, str[j]))
		{
			out[i++] = ' ';
			out[i++] = str[j];
			out[i] = ' ';
		}
		else
			out[i] = str[j];
		i++;
		j++;
	}
	out[i] = '\0';
	return (out);
}

char	**ft_strtok(char *str, char *set)
{
	char	**split;
	char	*spaced;
	char	**out;

	spaced = spacify(str, set);
	split = ft_split(set, ' ');
	out = ft_split (spaced, ' ');
	free(spaced);
	free(split);
	return (out);
}

// int		main(int ac, char **av)
// {
// 	int i = 0;
// 	char *out;
// 	char **toks;

// 	toks =ft_strtok(av[1],"<>;.");
// 	while (*toks)
// 	{
// 		printf("%s\n", *toks++);
// 		// toks++;
// 	}
// }