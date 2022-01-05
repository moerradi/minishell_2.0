/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:30:23 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/05 15:01:41 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_dict	*g_env;

int		handle_files(t_list	*files)
{
	int	i;
	int	*fd;
	int	err_tmp;
	i = ft_lstsize(files);
	fd = malloc(sizeof(int) * i);
	while (files != NULL)
	{
		if (((t_redir *)(files->content))->mode == do_redir)
			fd[i] = open(files->content, O_WRONLY | O_APPEND, 0777);
		else if (((t_redir *)(files->content))->mode == do_redir)
			fd[i] = open(files->content, O_WRONLY | O_CREAT, 0777);
		else if (((t_redir *)(files->content))->mode == do_redir)
			fd[i] = open(files->content, O_WRONLY | O_CREAT, 0777);
		close(fd[i]);
		if (fd[i] == -1)
		{
			err_tmp = errno;
			ft_putstr_fd( strerror(err_tmp), 2);
		}
		files = files->next;
		i++;
	}
	return (fd[i]);
}

int		is_builtin(t_pipe *cmd)
{
	if (!ft_strcmp(cmd->command, "echo"))
		return (echo(cmd->args, cmd->ac));
	else if (!ft_strcmp(cmd->command,"cd"))
		return (cd(cmd->args, cmd->ac));
	else if (!ft_strcmp(cmd->command,"env"))
		return(env());
	else if (!ft_strcmp(cmd->command,"unset"))
		return(unset(cmd->args, cmd->ac));
	else if (!ft_strcmp(cmd->command,"pwd"))
		return(pwd(cmd->args, cmd->ac));
	else if (!ft_strcmp(cmd->command,"exit"))
		return(ft_exit());
	else if (!ft_strcmp(cmd->command,"export"))
		return(export(cmd->args, cmd->ac));
	else
		return (127);
}

void	ft_execvp(char *cmd, char **args, char **env)
{
	char		**all_paths;
	char		*str;
	char		*path;
	char		*tmp;
	int			i;

	str = mdict_key_search(g_env, "PATH");
	all_paths = ft_split(str, ':');
	i = 0;
	while (all_paths[i] != NULL)
	{
		tmp = ft_strjoin("/", cmd);
		path = ft_strjoin(all_paths[i], tmp);
		free(tmp);
		execve(path, args, env);
		free(path);
		i++;
	}
	free_strs(all_paths);
	i = errno;
	ft_putstr_fd(strerror(i), 2);
}

void	single_cmd(t_list *cmd)
{
	// int	fd[2];
	int	pid1;
	int	out;
	int	in;
	char *path;

	// if (pipe(fd) == -1)
	// 	return;
	pid1 = fork(); //check fork failing
	path = get_path();
	if (pid1 == 0)
	{
		out = out_files(((t_pipe *)(cmd->content))->output_files);
		in = in_files(((t_pipe *)(cmd->content))->input_files);
		dup2(out, STDOUT_FILENO);
		if(!is_builtin((t_pipe *)cmd->content))
			ft_execvp(((t_pipe *)(cmd->content))->command,((t_pipe *)(cmd->content))->args, g_env);
		//close files;
	}
	//waitpid;
	//close files;
}

void	set_io(int *in, int *out, int fd[2])
{
	
}

void	run_cmd(t_list *cmd, int *exit_code)
{
	int	fd[2];
	int	in;
	int out;

	while (cmd!= NULL)
	{
		set_io(&in, &out, fd);
		*exit_code = is_builtin();
		if(*exit_code == 127)
			execute_cmd();
		if (out != 1)
            close(out);  
        if (in != 0)
            close(in);
		cmd = cmd->next;
	}
}
