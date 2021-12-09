/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 23:56:29 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/01 16:35:46 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_ptr(char **buffer)
{
	char	*buff;

	buff = *buffer;
	free(buff);
	return (NULL);
}

static char	*buffered_read(const int fd, char *rest)
{
	int		read_ret;
	char	*temp;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE < 1 || !buffer || read(fd, buffer, 0) < 0)
		return (NULL);
	while (!ft_strchr_s(rest, '\n'))
	{
		temp = rest;
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret < 0)
			return (free_ptr(&buffer));
		buffer[read_ret] = '\0';
		rest = ft_strjoin(rest, buffer);
		free(temp);
		if (read_ret == 0 || *rest == '\0')
			break ;
	}
	free(buffer);
	return (rest);
}

static int	gnl_helper(int newline_pos, char *temp, char *rest, char **line)
{
	newline_pos = temp - rest;
	temp = ft_strdup(temp + 1);
	*line = ft_strndup(rest, newline_pos);
	if (!temp || !(*line))
		return (-1);
	free(rest);
	rest = ft_strdup(temp);
	free(temp);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char			*temp;
	static char		*rest[ULILMIT];
	int				newline_pos;

	newline_pos = 0;
	rest[fd] = buffered_read(fd, rest[fd]);
	if (!rest[fd])
		return (-1);
	temp = ft_strchr_s(rest[fd], '\n');
	if (temp)
		return (gnl_helper(newline_pos, temp, rest[fd], line));
	else
	{
		*line = ft_strdup(rest[fd]);
		if (*line == NULL)
			return (-1);
		free(rest[fd]);
		rest[fd] = NULL;
		return (0);
	}
}
