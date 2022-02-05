/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:22:05 by moerradi          #+#    #+#             */
/*   Updated: 2022/02/05 14:33:19 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

extern char	**environ;

int	is_builtin(t_pipe *cmnd, int fd)
{
	if (!ft_strcmp(cmnd->cmd, "echo"))
		return (ft_echo(cmnd->args + 1, cmnd->ac - 1, fd));
	else if (!ft_strcmp(cmnd->cmd, "cd"))
		return (cd(cmnd->args + 1, cmnd->ac - 1));
	else if (!ft_strcmp(cmnd->cmd, "env"))
		return (env(fd));
	else if (!ft_strcmp(cmnd->cmd, "unset"))
		return (unset(cmnd->args + 1));
	else if (!ft_strcmp(cmnd->cmd, "pwd"))
		return (pwd(cmnd->ac - 1));
	else if (!ft_strcmp(cmnd->cmd, "exit"))
		return (bash_exit(cmnd->args + 1, cmnd->ac - 1));
	else if (!ft_strcmp(cmnd->cmd, "export"))
		return (export(cmnd->args + 1, cmnd->ac - 1, fd));
	else
		return (127);
}

void	redirect_io(int in, int out)
{
	if (in != 0)
		dup2(in, 0);
	if (out != 1)
	{
		dup2(out, 1);
		if (in != 0)
			close(in);
	}
}

int	exec_error(char *cmd)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(cmd, 2);
	if (is_dir(cmd))
	{
		ft_putstr_fd(": Is a directory\n", 2);
		return (126);
	}
	if (errno == ENOENT)
	{
		ft_putstr_fd(": command not found\n", 2);
		return (127);
	}
	else if (errno == EACCES)
	{
		ft_putstr_fd(": permission denied\n", 2);
		return (126);
	}
	return (127);
}

int	execute_cmd(t_pipe *cmnd, int in, int out)
{
	int		pid;
	int		status;

	status = is_builtin(cmnd, out);
	if (status == 127)
	{
		ft_putenv("-flag=1");
		pid = fork();
		if (pid < 0)
			return (ret_error("FATAL ERROR", 1));
		if (pid == 0)
		{
			if (in == -1)
				exit(1);
			redirect_io(in, out);
			if (ft_execvp(cmnd->cmd, cmnd->args) == -1)
				exit(exec_error(cmnd->cmd));
		}
		else
		{
			waitpid(pid, &status, 0);
			status = get_status(status);
		}
	}
	return (status);
}

void	run_cmd(t_list *cmd)
{
	int	fd[2];
	int	in;
	int	out;
	int	status;
	int	first;

	first = 1;
	status = 0;
	while (cmd != NULL)
	{
		if (first)
			in = 0;
		else
			in = fd[0];
		get_i_o(cmd, &in, &out, fd);
		if (((t_pipe *)cmd->content)->cmd)
			status = execute_cmd((t_pipe *)cmd->content, in, out);
		set_exit(status);
		if (out != 1)
			close(out);
		if (in != 0)
			close(in);
		first = 0;
		cmd = cmd->next;
	}
}
