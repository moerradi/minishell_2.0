/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 01:13:34 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/08 11:49:34 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	parsing_helper(t_pipe *pipe, char *str, t_list **tmp)
{
	t_list	*node;

	if (!str)
		return ;
	fix_token(str);
	if (!pipe->cmd)
		pipe->cmd = ft_strdup(str);
	node = ft_lstnew(ft_strdup(str));
	ft_lstadd_back(tmp, node);
	pipe->ac++;
}

bool	find_and_replace(t_list	*list, char *str)
{
	t_redir	*tmp;

	while (list)
	{
		tmp = (t_redir *)list->content;
		if (tmp->mode == di_redir)
		{
			free(tmp->file);
			tmp->file = ft_strdup(str);
			return (true);
		}
		list = list->next;
	}
	return (false);
}

static void	handle_redir(t_pipe *pipe, t_token t, char *str)
{
	t_list	*node;

	if (!str)
		return ;
	fix_token(str);
	if (t == di_redir)
		if (find_and_replace(pipe->input_files, str))
			return ;
	node = ft_lstnew(redir_new(str, t));
	if (t == si_redir || t == di_redir)
		ft_lstadd_back(&pipe->input_files, node);
	else
		ft_lstadd_back(&pipe->output_files, node);
}

static void	handle_expand(t_pipe *pipe, char *str, t_list **tmp)
{
	char	*tptr;

	tptr = expand_str(str);
	parsing_helper(pipe, tptr, tmp);
	free(tptr);
}

t_pipe	*parse_tokens(char **tokens)
{
	int		i;
	t_token	t;
	t_pipe	*out;
	t_list	*tmp;
	char	*tptr;

	i = 0;
	tmp = NULL;
	out = init_pipe();
	while (tokens[i])
	{
		t = get_token_type(tokens[i]);
		if (t == si_redir || t == di_redir || t == so_redir || t == do_redir)
			handle_redir(out, t, tokens[++i]);
		else
			parsing_helper(out, tokens[i], &tmp);
		i++;
	}
	out->args = lst_to_arr(tmp, out->ac);
	ft_lstclear(&tmp, free_str);
	return (out);
}
