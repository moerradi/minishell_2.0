/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 01:58:08 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/01 19:19:20 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	*handle_squote(bool *squote, char *out)
{
	if (*out == '\'')
		*squote = false;
	else if (ft_strchr(IGNORE_ALL, *out))
		*out = *out * (-1);
}

void	*handle_escape(bool *escape, char *out)
{
	if (ft_strchr(IGNORE_ALL, *out))
		*out = *out * (-1);
	*escape = false;
}

void	*handle_dquote(bool *escape, bool *dquote, char *out)
{
	if (*out == '\\')
	{
		if (ft_strchr(EQUOTE_IGNORE, *(out + 1)))
			*escape = true;
		else
			*out = *out * (-1);
	}
	else if (*out == '"')
		*dquote = false;
	if (ft_strchr(DQUOTE_IGNORE, *out))
		*out = *out * (-1);
}

void	*handle_normal(bool *squote, bool *dquote, bool *escape, char c)
{
	if (c == '\'')
		*squote = true;
	else if (c == '"')
		*dquote = true;
	else if (c == '\\')
		*escape = true;
}

char	*parse_quotes(char *line)
{
	int		i;
	bool	squote;
	bool	dquote;
	bool	escape;
	char	*out;

	squote = false;
	dquote = false;
	escape = false;
	i = 0;
	while (line[i])
	{
		if (squote)
			handle_squote(&squote, &line[i++]);
		else if (escape)
			handle_escape(&escape, &line[i++]);
		else if (dquote)
			handle_dquote(&escape, &dquote, &line[i++]);
		else
			handle_normal(&squote, &dquote, &escape, line[i++]);
	}
	if (squote || dquote || escape)
		return (NULL);
	out = removechars(line, "'\"\\");
	return (out);
}
