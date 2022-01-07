/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:30:23 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/07 04:39:32 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern char **environ;

void	ft_execvp(char *cmd, char **args)
{
	char		**all_paths;
	char		*str;
	char		*path;
	char		*tmp;
	int			i;

	str = getenv("PATH");
	all_paths = ft_split(str, ':');
	i = 0;
	while (all_paths[i])
	{
		tmp = ft_strjoin("/", cmd);
		path = ft_strjoin(all_paths[i], tmp);
		free(tmp);
		free(all_paths[i]);
		execve(path, args, environ);
		free(path);
		i++;
	}
	free(all_paths);
	i = errno;
	ft_putstr_fd(strerror(i), 2);
}

// int		is_builtin(t_pipe *cmd)
// {
// 	// remember > cmd->args + 1
// 	if (!ft_strcmp(cmd->command, "echo"))
// 		return (echo(cmd->args, cmd->ac));
// 	else if (!ft_strcmp(cmd->command,"cd"))
// 		return (cd(cmd->args, cmd->ac));
// 	else if (!ft_strcmp(cmd->command,"env"))
// 		return(env());
// 	else if (!ft_strcmp(cmd->command,"unset"))
// 		return(unset(cmd->args, cmd->ac));
// 	else if (!ft_strcmp(cmd->command,"pwd"))
// 		return(pwd(cmd->args, cmd->ac));
// 	else if (!ft_strcmp(cmd->command,"exit"))
// 		return(ft_exit());
// 	else if (!ft_strcmp(cmd->command,"export"))
// 		return(export(cmd->args, cmd->ac));
// 	else
// 		return (127);
// }

// void	ft_execvp(char *cmd, char **args, char **env)
// {
// 	char		**all_paths;
// 	char		*str;
// 	char		*path;
// 	char		*tmp;
// 	int			i;

// 	str = getenv("PATH");
// 	all_paths = ft_split(str, ':');
// 	i = 0;
// 	while (all_paths[i] != NULL)
// 	{
// 		tmp = ft_strjoin("/", cmd);
// 		path = ft_strjoin(all_paths[i], tmp);
// 		free(tmp);
// 		execve(path, args, env);
// 		free(path);
// 		i++;
// 	}
// 	free_strs(all_paths);
// 	i = errno;
// 	ft_putstr_fd(strerror(i), 2);
// }

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



// void redirect_io(int in, int out)
// {
//     if (in != 0)
//     {
//         dup2(in, 0);
//     }
//     if (out != 1)
//     {
//         dup2(out, 1);
//         close(in);
//     }
// }

// int execute_command(t_pipe *cmd, int in, int out)
// {
// 	int pid;
// 	int status = 127;

// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		redirect(in, out);
// 		status = is_builtin(cmd);
// 		if (status == 127)
// 		{
// 			if(execve(cmd->command, cmd->args, environ) == -1)
// 			{
// 				ft_putstr_fd("error: cannot execute ", 2);
// 				ft_putstr_fd(cmd->command, 2);
// 				ft_putstr_fd("\n", 2);
// 				exit(0);
// 			}
// 		}
// 		exit(0);
// 	}
// 	else
// 		pid = waitpid(pid, &status, WUNTRACED);
// 	return (status);
// }



// void	run_cmd(t_list *cmd, int *exit_code)
// {
// 	int	fd[2];
// 	int	in;
// 	int out;
// 	int status;
// 	int first;

// 	first = true;
// 	while (cmd!= NULL)
// 	{
// 		get_i_o((t_pipe *)cmd->content,&in, &out, fd);
// 		if (first && in == fd[0])
// 			in = 0;
// 		if (!cmd->next && out == fd[1])
// 			out = 1;
// 		status = execute_cmd((t_pipe *)cmd->content, in , out);
// 		if (out != 1)
// 			close(out);  
// 		if (in != 0)
// 			close(in);
// 		first = false;
// 		cmd = cmd->next;
// 	}
// }

// int		main(int ac, char **av)
// {
// 	t_list *files;
// 	t_list *file1;
// 	t_list *file2;
// 	t_redir *f;
// 	t_redir *t;
// 	t_redir *k;
// 	char *line;
// 	int fd = 1;


// 	f = redir_new(av[1], si_redir);
// 	t = redir_new(av[2], si_redir);
// 	k = redir_new(av[3], di_redir);
// 	files = ft_lstnew(f);
// 	file1 = ft_lstnew(t);
// 	file2 = ft_lstnew(k);
// 	ft_lstadd_back(&files, file1);
// 	ft_lstadd_back(&files, file2);
// 	fd = in_files(files);
	
// 	while (get_next_line(fd, &line))
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	printf("%s\n", line);
// 	free(line);
// 	printf("%d\n", fd);
// 	ft_lstclear(&files, &free_redir);
// 	close(fd);
// }
