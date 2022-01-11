 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_i_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:43:19 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/09 03:51:44 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

extern char	**environ;

int	out_files(t_list *files)
{
	int		fd;
	t_redir	*tmp;

	fd = 1;
	while (files != NULL)
	{
		tmp = (t_redir *)files->content;
		if (tmp->mode == d_out)
			fd = open(tmp->file, O_RDWR | O_APPEND | O_CREAT, 0777);
		else if (tmp->mode == s_out)
			fd = open(tmp->file, O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			perror(tmp->file);
		if (files->next)
			close(fd);
		files = files->next;
	}
	return (fd);
}

int	handle_d_i(t_redir *tmp)
{
	int		pp[2];
	char	*line;

	pipe(pp);
	line = readline("> ");
	if (ft_strcmp(line, tmp->file))
		ft_putendl_fd(line, pp[1]);
	while (ft_strcmp(line, tmp->file))
	{
		free(line);
		line = readline("> ");
		if (ft_strcmp(line, tmp->file))
			ft_putendl_fd(line, pp[1]);
	}
	free(line);
	close(pp[1]);
	return (pp[0]);
}

int	in_files(t_list *files)
{
	int		fd;
	t_redir	*tmp;

	fd = 0;
	while (files != NULL)
	{
		tmp = (t_redir *)files->content;
		if (tmp->mode == s_in)
			fd = open(tmp->file, O_RDONLY, 0777);
		else if (tmp->mode == d_in)
			fd = handle_d_i(tmp);
		if (fd == -1)
			perror(tmp->file);
		if (files->next)
			close(fd);
		files = files->next;
	}
	return (fd);
}

void	get_i_o(t_list *cmd, int *in, int *out, int fd[2], int first)
{
	if (first)
		*in = 0;
	else
		*in = fd[0];
	if(cmd->next)
	{
		if (pipe(fd) == -1)
			return (ft_putendl_fd("IO error", 2));
		*out = fd[1];
	}
	else
		*out = 1;
	if (((t_pipe *)cmd->content)->input_files)
	{
		*in = in_files(((t_pipe *)cmd->content)->input_files);
		close(fd[0]);
	}
	if(((t_pipe *)cmd->content)->output_files)
	{
		*out = out_files(((t_pipe *)cmd->content)->output_files);
		close(fd[1]);
	}
}
