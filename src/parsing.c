/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:05:20 by moerradi          #+#    #+#             */
/*   Updated: 2021/12/14 20:03:02 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

bool	parse_errors(char *line)
{
	int		i;
	bool	squote;
	bool	dquote;
	bool	escape;
	bool	special;
	char

	squote = false;
	dquote = false;
	escape = false;
	i = 0;
	while (line[i])
	{
		if (escape)
			escape = false;
		else if (line[i] == '\'' && !dquote)
			squote = !squote;
		else if (line[i] == '"' && !squote)
			dquote = !dquote;
		else if (is_bash_special(line[i]))
			special = true;
		else if (line[i] == '\\')
			escape = true;
		i++;
	}
	
	if (squote || dquote || escape)
		printf("parse error");
}

bool	istoken(char c)
{
	
}

t_list	*parse(char *line)
{
	int i;
	char	*tr_line;

	i = 0;
	tr_line = ft_strtrim(line, " \t");
	if (tr_line[0] == '|')
	{
		printf("bash: parse error near '|'");
		free(tr_line);
		return (NULL);
	}
	while (tr_line[i])
	{
		if (istoken(tr_line))
	}
}

int	 main(int argc, char ** argv)
{
	parse_errors(argv[1]);	
}
