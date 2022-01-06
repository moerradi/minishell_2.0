/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 01:13:34 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/05 20:05:26 by moerradi         ###   ########.fr       */
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

static void	parsing_helper(t_pipe *pipe, char *str, t_list **tmp)
{
	t_list	*node;

	fix_token(str);
	if (!pipe->cmd)
		pipe->cmd = ft_strdup(str);
	else
	{
		node = ft_lstnew(ft_strdup(str));
		ft_lstadd_back(tmp, node);
		pipe->ac++;
	}
}

static void	*handle_redir(t_pipe *pipe, t_token t, char *str)
{
	t_list	*node;
	
	fix_token(str);
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
	t_list	*tmp;

	i = 0;
	tmp = NULL;
	out = init_pipe();
	while (tokens[i])
	{
		t = get_token_type(tokens[i]);
		if (t == si_redir || t == di_redir || t == so_redir || t == do_redir)
			handle_redir(out, t, tokens[++i]);
		// else if (t == dollar)
		// {
		// 	if (get_token_type(tokens[i + 1]) != nontoken)
		// 		parsing_helper(out, tokens[i], &tmp);
		// 	else
		// 		parsing_helper(out, expand(tokens[++i]), &tmp);
		// }
		else
			parsing_helper(out, expand_str(tokens[i]), &tmp);
		i++;
	}
	out->args = lst_to_arr(tmp, out->ac);
	ft_lstclear(&tmp, free_str);
	return (out);
}
