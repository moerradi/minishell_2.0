/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_i_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:43:19 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/06 20:21:17 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

extern char	**environ;

int	out_files(t_list *files)
{
	int		fd;
	t_redir	*tmp;

	while (files != NULL)
	{
		tmp = (t_redir *)files->content;
		if (tmp->mode == do_redir)
			fd = open(tmp->file, O_RDWR | O_APPEND | O_CREAT, 0777);
		else if (tmp->mode == so_redir)
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
	char	*line;
	t_redir	*tmp;
	int		pp[2];

	while (files != NULL)
	{
		tmp = (t_redir *)files->content;
		if (tmp->mode == si_redir)
			fd = open(tmp->file, O_RDONLY, 0777);
		else if (tmp->mode == di_redir)
			fd = handle_d_i(tmp);
		if (fd == -1)
			perror(tmp->file);
		if (files->next)
			close(fd);
		files = files->next;
	}
	return (fd);
}

void	get_i_o(t_pipe *cmd, int *in, int *out, int fd[2])
{
	*in = fd[0];
	pipe(fd);
	*out = fd[1];
	*out = out_files(cmd->output_files);
	*in = in_files(cmd->input_files);
}
