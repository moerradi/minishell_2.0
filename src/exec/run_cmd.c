/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:30:23 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/09 00:25:22 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

extern char **environ;


int		is_builtin(t_pipe *cmnd)
{
	if (!ft_strcmp(cmnd->cmd, "echo"))
		return (echo(cmnd->args + 1, cmnd->ac - 1 ));
	else if (!ft_strcmp(cmnd->cmd,"cd"))
		return (cd(cmnd->args + 1, cmnd->ac - 1));
	else if (!ft_strcmp(cmnd->cmd,"env"))
		return(env());
	else if (!ft_strcmp(cmnd->cmd,"unset"))
		return(unset(cmnd->args + 1));
	else if (!ft_strcmp(cmnd->cmd,"pwd"))
		return(pwd(cmnd->args + 1, cmnd->ac - 1));
	else if (!ft_strcmp(cmnd->cmd,"exit"))
		return(bash_exit(cmnd->args + 1, cmnd->ac - 1));
	else if (!ft_strcmp(cmnd->cmd,"export"))
		return(export(cmnd->args + 1, cmnd->ac - 1));
	else
		return (127);
}



// void	single_cmd(t_list *cmd)
// {
// 	// int	fd[2];
// 	int	pid1;
// 	int	out;
// 	int	in;
// 	char *path;

// 	// if (pipe(fd) == -1)
// 	// 	return;
// 	pid1 = fork(); //check fork failing
// 	path = get_path();
// 	if (pid1 == 0)
// 	{
// 		out = out_files(((t_pipe *)(cmd->content))->output_files);
// 		in = in_files(((t_pipe *)(cmd->content))->input_files);
// 		dup2(out, STDOUT_FILENO);
// 		if(!is_builtin((t_pipe *)cmd->content))
// 			ft_execvp(((t_pipe *)(cmd->content))->command,((t_pipe *)(cmd->content))->args, g_env);
// 		//close files;
// 	}
// 	//waitpid;
// 	//close files;
// }



void redirect_io(int in, int out)
{
    if (in != 0)
    {
        dup2(in, 0);
    }
    if (out != 1)
    {
        dup2(out, 1);
        close(in);
    }
}

int execute_cmd(t_pipe *cmnd, int in, int out)
{
	int pid;
	int status = 127;

	pid = fork();
	if (pid == 0)
	{
		redirect_io(in, out);
		status = is_builtin(cmnd);
		if (status == 127)
		{
			if(execve(cmnd->cmd, cmnd->args, environ) == -1)
			{
				ft_putstr_fd("error: cannot execute ", 2);
				ft_putstr_fd(cmnd->cmd, 2);
				ft_putstr_fd("\n", 2);
				exit(0);
			}
		}
		exit(0);
	}
	else
		pid = waitpid(pid, &status, WUNTRACED);
	return (status);
}

void	run_cmd(t_list *cmd)
{
	int	fd[2];
	int	in;
	int out;
	int status;
	int first;

	first = true;
	while (cmd!= NULL)
	{
		// in = 0;
		// out = 1;
		get_i_o((t_pipe *)cmd->content,&in, &out, fd);
		printf("in = %i\nout = %i\n", in, out);
		// if (first && in == fd[0])
		// 	in = 0;
		// if (!cmd->next && out == fd[1])
		// 	out = 1;
		// status = execute_cmd((t_pipe *)cmd->content, in , out);
		if (out != 1)
			close(out);  
		if (in != 0)
			close(in);
		first = false;
		cmd = cmd->next;
	}
}
