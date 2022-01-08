/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:22:11 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/06 20:26:44 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*ret_free(char *str)
{
	free(str);
	return (NULL);
}

void	free_redir(void *redir)
{
	t_redir	*tmp;

	tmp = (t_redir *)redir;
	free(tmp->file);
	free(redir);
	redir = NULL;
}

void	free_str(void *str)
{
	free(str);
	str = NULL;
}

void	free_pipe(void	*pipe)
{
	t_pipe	*tmp;

	tmp = (t_pipe *) pipe;
	free(tmp->cmd);
	free_strs(tmp->args);
	ft_lstclear(&tmp->input_files, &free_redir);
	ft_lstclear(&tmp->output_files, &free_redir);
	free(pipe);
	pipe = NULL;
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	strs = NULL;
}
