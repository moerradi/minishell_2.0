/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 02:07:40 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/02/05 17:47:21 by moerradi         ###   ########.fr       */
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

static void	handle_double_tok(char *out, char *str, int *i, int *j)
{
	out[(*i)++] = ' ';
	out[(*i)++] = str[(*j)++];
	out[(*i)++] = str[(*j)++];
	out[(*i)++] = ' ';
}

static char	*spacify(char *str, const char *set, int len)
{
	char	*out;
	int		i;
	int		j;

	j = 0;
	i = 0;
	out = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		if (ft_strchr(set, str[j]) && str[j] == str[j + 1])
			handle_double_tok(out, str, &i, &j);
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
	if (len != (int)ft_strlen(str))
	{
		spaced = spacify(str, set, len);
		out = ft_split(spaced, ' ');
		free(spaced);
	}
	else
		out = ft_split(str, ' ');
	return (out);
}
