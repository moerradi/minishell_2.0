/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:30:23 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/10 11:45:47 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

extern char **environ;


int		is_builtin(t_pipe *cmnd, int fd)
{
	if (!ft_strcmp(cmnd->cmd, "echo"))
		return (echo(cmnd->args + 1, cmnd->ac - 1, fd));
	else if (!ft_strcmp(cmnd->cmd,"cd"))
		return (cd(cmnd->args + 1, cmnd->ac - 1));
	else if (!ft_strcmp(cmnd->cmd,"env"))
		return(env(fd));
	else if (!ft_strcmp(cmnd->cmd,"unset"))
		return(unset(cmnd->args + 1));
	else if (!ft_strcmp(cmnd->cmd,"pwd"))
		return(pwd(cmnd->ac - 1));
	else if (!ft_strcmp(cmnd->cmd,"exit"))
		return(bash_exit(cmnd->args + 1, cmnd->ac - 1));
	else if (!ft_strcmp(cmnd->cmd,"export"))
		return(export(cmnd->args + 1, cmnd->ac - 1, fd));
	else
		return (127);
}

void redirect_io(int in, int out)
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

int execute_cmd(t_pipe *cmnd, int in, int out)
{
	int pid;
	int status = 127;

	status = is_builtin(cmnd, out);
	if (status == 127)
	{
		pid = fork();
		if (pid < 0)
			return(ret_error("FATAL ERROR", 1));
		if (pid == 0)
		{
			redirect_io(in, out);
			if (ft_execvp(cmnd->cmd, cmnd->args) == -1)
			{
				if(errno == ENOENT)
				{
					ft_putstr_fd(cmnd->cmd, 2);
					ft_putstr_fd(": command not found\n", 2);
				}
				else if (errno == EACCES)
				{
					ft_putstr_fd(cmnd->cmd, 2);
					ft_putstr_fd(": command not found\n", 2);
				}
			}
			exit(0);
		}
		else
			pid = waitpid(pid, &status, WUNTRACED);
	}
	return (status);
}

void	run_cmd(t_list *cmd)
{
	int	fd[2];
	int	in;
	int out;
	int status;
	int	first;

	first = 1;
	while (cmd!= NULL)
	{
		get_i_o(cmd, &in, &out, fd, first);
		// printf("in = %i\nout = %i\n", in, out);
		if(((t_pipe *)cmd->content)->cmd)
			status = execute_cmd((t_pipe *)cmd->content, in , out);
		if (out != 1)
			close(out);  
		if (in != 0)
			close(in);
		first = 0;
		cmd = cmd->next;
	}
}
