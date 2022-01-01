/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:05:20 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/01 01:23:21 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_dict	*g_env;

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
				if (ft_strchr(EQUOTE_IGNORE, out[i + 1]))
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

void	fix_token(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] < 0)
		{
			str[i] = str[i] * (-1);
		}
		i++;
	}
}

bool	validate_redirs(char **tokens)
{
	int		i;
	t_token	t;
	bool	active;

	i = 0;
	active = false;
	while (tokens[i])
	{
		t = get_token_type(tokens[i]);
		if (t == si_redir || t == di_redir || t == so_redir || t == do_redir)
		{
			if (active)
				return (false);
			active = true;
		}
		else
		{
			if (active)
				active = false;
		}
	}
	if (active)
		return (false);
	return (true);
}

t_list	*lexer(char **pipes)
{
	int		i;
	t_list	*out;
	t_list	*node;
	char	**tokens;

	out = NULL;
	i = 0;
	while (pipes[i])
	{
		tokens = ft_strtok(pipes[i], "><$");
		if (!validate_redirs(tokens))
		{
			ft_lstclear(&out, &free_pipe);
			return (NULL);
		}
		node = ft_lstnew(parse_tokens(tokens));
		ft_lstadd_back(&out, node);
		i++;
	}
	return (out);
}

t_list	*parse(char *cmd)
{
	char	**pipes;
	char	*tmp;
	t_list	*ret;

	tmp = parse_quotes(cmd);
	if (!tmp)
		return (NULL);
	pipes = split_pipes(tmp);
	free(tmp);
	if (!pipes)
		return (NULL);
	ret = lexer(pipes);
	free_strs(pipes);
	return (ret);
}