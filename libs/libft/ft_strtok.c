/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 02:07:40 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/08 01:52:32 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../../headers/minishell.h"

static int	space_len(char *str, const char *set)
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

static char	*spacify(char *str, const char *set, int len)
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

char	**ft_strtok(char *str, const char *set)
{
	char	*spaced;
	char	**out;
	int		len;

	len = space_len(str, set);
	spaced = spacify(str, set, len);
	out = ft_split(spaced, ' ');
	free(spaced);
	return (out);
}

int		main(int ac, char **av)
{
	char *str = ft_strdup(av[1]);
	char *tmp = parse_quotes(av[1]);
	int len = space_len(tmp, "<>");
	int i = ft_strlen(tmp);
	printf("strlen = %i\n", i);
	printf("len = %i\n", len);
	printf("parse = %s\n", tmp);
	char **args = ft_strtok(tmp, "><");
	printf("tok = %i\n", args[2][19]);
}