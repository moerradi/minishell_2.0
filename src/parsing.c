/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:05:20 by moerradi          #+#    #+#             */
/*   Updated: 2021/12/21 00:20:06 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int		count_qns_less(char	*str)
{
	int	i;
	int	qnsc;

	i = 0;
	qnsc = 0;
	while (str[i])
	{
		if (str[i] == '\\' || str[i] == '\'' || str[i] == '"')
			qnsc++;
		i++;
	}
	return (i - qnsc);
}

char	*remove_qns(char	*str)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	out = malloc(sizeof(char) * (count_qns_less(str) + 1));
	if (!out)
		return (NULL);
	while (str[i])
	{
		if (str[i] != '\\' && str[i] != '\'' && str[i] != '"')
		{
			out[j] = str[i]; 
			j++;
		}
		i++;
	}
	out[j] = '\0';
	return (out);
}

char	*parse_quotes(char *line)
{
	int i;
	bool	squote;
	bool	dquote;
	bool	escape;
	char	*out;
	char	*final;

	squote = false;
	dquote = false;
	escape = false;
	out = ft_strdup(line);
	i = 0;

	while (out[i])
	{
		if (squote)
		{
			if (out[i] == '\'')
				squote = false;
			else if (ft_strchr(IGNORE_ALL, out[i]))
				out[i] = out[i] * (-1);
		}
		else if (escape)
		{
			if (ft_strchr(IGNORE_ALL, out[i]))
				out[i] = out[i] * (-1);
			escape = false;
		}
		else if (dquote)
		{
			if (out[i] == '\\')
			{
				if (out[i + 1] == '$' || out[i + 1] == '"')
					escape = true;
				else
					out[i] = out[i] * (-1);

			}
			else if (out[i] == '"')
				dquote = false;
			if (ft_strchr(DQUOTE_IGNORE, out[i]))
				out[i] = out[i] * (-1);
		}
		else
		{
			if (line[i] == '\'')
				squote = true;
			else if (line[i] == '"')
				dquote = true;
			else if (line[i] == '\\')
				escape = true;
		}
		i++;
	}
	if (squote || dquote || escape)	
	{
		free(out);
		return (NULL);
	}
	final = remove_qns(out);
	free(out);
	return (final);
}



// we split by pipes but if a  trimmed line starts or ends with a pipe or has consecutive pipes then its a parse error;
// now we have a double array of pipes
// for each element of the array we are going to first parse the quotes
///ignore backslash ignore token is precieded by backslash 
// dquote ingonres all special (tokens) except the dollar sign and backslash
// squote ignores all special (tokens) exept backslash



void	fix_tokens(char **str)
{
	int i;
	char *tmp;
	
	tmp = *str;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] < 0)
		{
			tmp[i] = tmp[i] * (-1);
		}
		i++;
	}
}
