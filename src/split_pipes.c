/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:27:35 by moerradi          #+#    #+#             */
/*   Updated: 2021/12/18 16:42:43 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static size_t	count_pipes(char *str)
{
	int		t;
	size_t	wc;

	t = 1;
	wc = 0;
	while (*str)
	{
		if (*str == '|')
		{
			if (t == 1)
				return (0);
			t = 1;
		}
		else if (t == 1)
		{
			t = 0;
			wc++;
		}
		str++;
	}
	if (t == 1)
		return (0);
	return (wc);
}

static char	**ft_garbage(char ***s, size_t idx)
{
	char	**splitout;
	size_t	i;

	i = 0;
	splitout = *s;
	while (i < idx)
	{
		free(splitout[i]);
		i++;
	}
	free(splitout);
	splitout = NULL;
	return (splitout);
}

char	**ft_split_pipes(char *s)
{
	char			**out;
	size_t			i;
	unsigned int	start;
	size_t			len;
	size_t			pc;

	i = 0;
	start = 0;
	pc = count_pipes(s);
	if (pc == 0)
		return (NULL);
	out = malloc(sizeof(char *) * pc + 1);
	if (s == NULL || !out)
		return (NULL);
	while (i < pc)
	{
		len = 0;
		while (s[start] && s[start] == '|')
			start++;
		while (s[len + start] && s[len + start] != '|')
			len++;
		out[i] = ft_substr(s, start, len);
		if (!out[i++])
			return (ft_garbage(&out, i - 1));
		start += len;
	}
	out[i] = NULL;
	return (out);
}


int main(int ac, char **av)
{
	int i = 0;
	char **test = ft_split_pipes(av[1]);
	if (test == NULL)
		printf("parse error\n");
	else
		while(test[i])
		printf("%s\n", test[i++]);
}