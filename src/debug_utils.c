/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:47:16 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/01 19:32:08 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_putstr(void *str)
{
	printf("%s ", (char *)str);
}

void	ft_putredir(void *redir)
{
	t_redir *tmp;

	tmp = (t_redir *) redir;
	printf("%s-%i ", tmp->file, tmp->mode);
}

void	deb_print_pipe(void *pipe)
{
	t_pipe	*tmp;

	tmp = (t_pipe *) pipe;
	printf("command : %s\n", tmp->command);
	printf("arguments: ");
	ft_lstiter(tmp->args, &ft_putstr);
	printf("\n");
	printf("input files: ");
	ft_lstiter(tmp->input_files, &ft_putredir);
	printf("\n");
	printf("output files: ");
	ft_lstiter(tmp->output_files, &ft_putredir);
	printf("\n");
}

void	deb_print_strarr(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
		printf("%s\n", strs[i++]);
}
