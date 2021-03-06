/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:05:20 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/09 00:18:56 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_token	get_token_type(char	*token)
{
	if (!ft_strcmp(token, ">"))
		return (s_out);
	else if (!ft_strcmp(token, "<"))
		return (s_in);
	else if (!ft_strcmp(token, ">>"))
		return (d_out);
	else if (!ft_strcmp(token, "<<"))
		return (d_in);
	else if (!ft_strcmp(token, "$"))
		return (dollar);
	else
		return (nontoken);
}

void	fix_token(char *str)
{
	int	i;

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
		t = get_token_type(tokens[i++]);
		if (t == s_in || t == d_in || t == s_out || t == d_out)
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
		tokens = ft_strtok(pipes[i], "><");
		if (!validate_redirs(tokens))
		{
			ft_lstclear(&out, &free_pipe);
			free_strs(tokens);
			return (NULL);
		}
		node = ft_lstnew(parse_tokens(tokens));
		free_strs(tokens);
		ft_lstadd_back(&out, node);
		i++;
	}
	return (out);
}

t_list	*parse(char *cmd)
{
	char	**pipes;
	char	*tmp;
	char	*tmp2;
	t_list	*ret;

	tmp = parse_quotes(cmd);
	if (!tmp)
		return (NULL);
	tmp2 = handle_env(tmp);
	free(tmp);
	tmp = removechars(tmp2, "'\"\\");
	free(tmp2);
	pipes = split_pipes(tmp);
	free(tmp);
	if (!pipes)
		return (NULL);
	ret = lexer(pipes);
	free_strs(pipes);
	return (ret);
}
