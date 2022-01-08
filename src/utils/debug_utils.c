/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:47:16 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/08 03:23:08 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_putredir(void *redir)
{
	t_redir	*tmp;

	tmp = (t_redir *) redir;
	printf("%s-%i ", tmp->file, tmp->mode);
}

void	deb_print_pipe(void *pipe)
{
	t_pipe	*tmp;

	tmp = (t_pipe *) pipe;
	printf("command : %s\n", tmp->cmd);
	printf("arguments: ");
	deb_print_strarr(tmp->args);
	printf("\n");
	printf("arguments count: %i\n", tmp->ac);
	printf("input files: ");
	ft_lstiter(tmp->input_files, &ft_putredir);
	printf("\n");
	printf("output files: ");
	ft_lstiter(tmp->output_files, &ft_putredir);
	printf("\n");
}

void	deb_print_strarr(char **strs)
{
	int	i;

	i = 0;
	if (!strs[0])
		return ;
	while (strs[i + 1])
		printf("%s - ", strs[i++]);
	printf("%s", strs[i]);
}
