/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 01:10:02 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/01 01:10:23 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_redir	*redir_new(char *path, t_token mode)
{
	t_redir	*out;

	out = (t_redir *)malloc(sizeof(t_redir));
	out->file = ft_strdup(path);
	out->mode = mode;
	return (out);
}

t_pipe	*init_pipe()
{
	t_pipe	*out;

	out = (t_pipe*)malloc(sizeof(t_pipe ));
	out->args = NULL;
	out->command = NULL;
	out->input_files = NULL;
	out->output_files = NULL;
	return (out);
}