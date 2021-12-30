/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:05:20 by moerradi          #+#    #+#             */
/*   Updated: 2021/12/29 16:05:22 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_dict	*g_env;

int		count_qns_less(char	*str)
{
	int	i;
	int	qnsc;

	i = 0;
	qnsc = 0;
	while (str[i])
	{
		if (str[i] == '\\' || str[i] == '\'' || str[i] == '"')
			qnsc++;
		i++;
	}
	return (i - qnsc);
}

char	*remove_qns(char	*str)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	out = malloc(sizeof(char) * (count_qns_less(str) + 1));
	if (!out)
		return (NULL);
	while (str[i])
	{
		if (str[i] != '\\' && str[i] != '\'' && str[i] != '"')
		{
			out[j] = str[i]; 
			j++;
		}
		i++;
	}
	out[j] = '\0';
	return (out);
}

char	*parse_quotes(char *line)
{
	int i;
	bool	squote;
	bool	dquote;
	bool	escape;
	char	*out;
	char	*final;

	squote = false;
	dquote = false;
	escape = false;
	out = ft_strdup(line);
	i = 0;

	while (out[i])
	{
		if (squote)
		{
			if (out[i] == '\'')
				squote = false;
			else if (ft_strchr(IGNORE_ALL, out[i]))
				out[i] = out[i] * (-1);
		}
		else if (escape)
		{
			if (ft_strchr(IGNORE_ALL, out[i]))
				out[i] = out[i] * (-1);
			escape = false;
		}
		else if (dquote)
		{
			if (out[i] == '\\')
			{
				if (ft_strchr(EQUOTE_IGNORE, out[i + 1]))
					escape = true;
				else
					out[i] = out[i] * (-1);

			}
			else if (out[i] == '"')
				dquote = false;
			if (ft_strchr(DQUOTE_IGNORE, out[i]))
				out[i] = out[i] * (-1);
		}
		else
		{
			if (line[i] == '\'')
				squote = true;
			else if (line[i] == '"')
				dquote = true;
			else if (line[i] == '\\')
				escape = true;
		}
		i++;
	}
	if (squote || dquote || escape)	
	{
		free(out);
		return (NULL);
	}
	final = remove_qns(out);
	free(out);
	return (final);
}

void	fix_tokens(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] < 0)
		{
			str[i] = str[i] * (-1);
		}
		i++;
	}
}

t_token get_token_type(char	*token)
{
	if (!ft_strcmp(token, ">"))
		return (so_redir);
	else if (!ft_strcmp(token, "<"))
		return (si_redir);
	else if (!ft_strcmp(token, ">>"))
		return (do_redir);
	else if (!ft_strcmp(token, "<<"))
		return (di_redir);
	else if (!ft_strcmp(token, "$"))
		return (dollar);
	else
		return (nontoken);
}

bool	validate_redirs(char **tokens)
{
	int		i;
	t_token	t;
	bool	active;

	i = 0;
	active = false;
	while (tokens[i])
	{
		t = get_token_type(tokens[i]);
		if (t == si_redir || t == di_redir || t == so_redir || t == do_redir)
		{
			if (active)
				return (false);
			active = true;
		}
		else
		{
			if (active)
				active = false;
		}
	}
	if (active)
		return (false);
	return (true);
}

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

void	parsing_helper(t_pipe *pipe, const char *str)
{
	t_list	*node;
	if (!pipe->command)
		pipe->command = ft_strdup(str);
	else
	{
		node = ft_lstnew(ft_strdup(str));
		ft_lstadd_back(&pipe->args, node);
	}
		
}

void	*handle_redir(t_pipe *pipe, t_token t, char *str)
{
	t_list	*node;

	node = ft_lstnew(redir_new(str, t));
	if (t == si_redir || t == di_redir)
		ft_lstadd_back(&pipe->input_files, node);
	else
		ft_lstadd_back(&pipe->output_files, node);
}

t_pipe	*finalize_parsing(char **tokens)
{
	int		i;
	t_token	t;
	t_pipe	*out;
	
	i = 0;
	out = init_pipe();
	while (tokens[i])
	{
		t = get_token_type(tokens[i]);
		if (t == si_redir || t == di_redir || t == so_redir || t == do_redir)
			handle_redir(out, t, tokens[++i]);
		else if (t == dollar)
		{
			if (get_token_type(tokens[i + 1]) != nontoken)
				parsing_helper(out, tokens[i]);
			else
				parsing_helper(out, expand(tokens[++i]));
		}
		else
			parsing_helper(out, tokens[i]);
		i++;
	}
	return (out);
}

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

void	deb_print_pipe(t_pipe *pipe)
{
	printf("command : %s\n", pipe->command);
	printf("arguments: ");
	ft_lstiter(pipe->args, &ft_putstr);
	printf("\n");
	printf("input files: ");
	ft_lstiter(pipe->input_files, &ft_putredir);
	printf("\n");
	printf("output files: ");
	ft_lstiter(pipe->output_files, &ft_putredir);
	printf("\n");
}

void	free_redir(void *redir)
{
	t_redir	*tmp;

	tmp = (t_redir *)redir;
	free(tmp->file);
	free(redir);
	redir = NULL;
}
 
void	free_str(void *str)
{
	free(str);
	str = NULL;
}

void	free_pipe(void	*pipe)
{
	t_pipe	*tmp;

	tmp = (t_pipe *) pipe;
	free(tmp->command);
	ft_lstclear(tmp->args, &free_str);
	ft_lstclear(tmp->input_files, &free_redir);
	ft_lstclear(tmp->output_files, &free_redir);
}