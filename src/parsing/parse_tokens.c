/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 01:13:34 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/01 19:42:32 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_token	get_token_type(char	*token)
{
	if (!ft_strcmp(token, ">"))
		return (so_redir);
	else if (!ft_strcmp(token, "<"))
		return (si_redir);
	else if (!ft_strcmp(token, ">>"))
		return (do_redir);
	else if (!ft_strcmp(token, "<<"))
		return (di_redir);
	else if (!ft_strcmp(token, "$"))
		return (dollar);
	else
		return (nontoken);
}

static void	parsing_helper(t_pipe *pipe, char *str)
{
	t_list	*node;

	if (!pipe->command)
		pipe->command = ft_strdup(str);
	else
	{
		node = ft_lstnew(ft_strdup(str));
		ft_lstadd_back(&pipe->args, node);
	}
}

static void	*handle_redir(t_pipe *pipe, t_token t, char *str)
{
	t_list	*node;

	node = ft_lstnew(redir_new(str, t));
	if (t == si_redir || t == di_redir)
		ft_lstadd_back(&pipe->input_files, node);
	else
		ft_lstadd_back(&pipe->output_files, node);
}

t_pipe	*parse_tokens(char **tokens)
{
	int		i;
	t_token	t;
	t_pipe	*out;

	i = 0;
	out = init_pipe();
	while (tokens[i])
	{
		fix_token(tokens[i]);
		t = get_token_type(tokens[i]);
		if (t == si_redir || t == di_redir || t == so_redir || t == do_redir)
			handle_redir(out, t, tokens[++i]);
		else if (t == dollar)
		{
			if (get_token_type(tokens[i + 1]) != nontoken)
				parsing_helper(out, tokens[i]);
			else
				parsing_helper(out, expand(tokens[++i]));
		}
		else
			parsing_helper(out, tokens[i]);
		i++;
	}
	return (out);
}
