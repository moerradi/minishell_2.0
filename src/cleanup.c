/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:22:11 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/01 01:15:41 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	free_redir(void *redir)
{
	t_redir	*tmp;

	tmp = (t_redir *)redir;
	free(tmp->file);
	free(redir);
	redir = NULL;
}

static void	free_str(void *str)
{
	free(str);
	str = NULL;
}

void	free_pipe(void	*pipe)
{
	t_pipe	*tmp;

	tmp = (t_pipe *) pipe;
	free(tmp->command);
	ft_lstclear(tmp->args, &free_str);
	ft_lstclear(tmp->input_files, &free_redir);
	ft_lstclear(tmp->output_files, &free_redir);
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
