/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 23:56:29 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/06 02:01:55 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char    *free_ptr(char **buffer)
{
    char *buff;

    buff = *buffer;
    free(buff);
    return (NULL);
}

char    *buffered_read(const int fd, char *rest)
{
    int        read_ret;
    char    *temp;
    char    *buffer;

    if (fd < 0 || BUFFER_SIZE < 1 || !(buffer = malloc(sizeof(char) * \
        (BUFFER_SIZE + 1))) || read(fd, buffer, 0) < 0)
        return (NULL);
    while (!ft_strchr_s(rest, '\n'))
    {
        temp = rest;
        if ((read_ret = read(fd, buffer, BUFFER_SIZE)) < 0)
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

int        get_next_line(int fd, char **line)
{
    char            *temp;
    static char        *rest[ULILMIT];
    int                newline_pos;

    if (!(rest[fd] = buffered_read(fd, rest[fd])))
        return (-1);
    if (((temp = ft_strchr_s(rest[fd], '\n'))))
    {
        newline_pos = temp - rest[fd];
        temp = ft_strdup(temp + 1);
        if (!temp || !(*line = ft_strndup(rest[fd], newline_pos)))
            return (-1);
        free(rest[fd]);
        rest[fd] = ft_strdup(temp);
        free(temp);
        return (1);
    }
    else
    {
        if ((*line = ft_strdup(rest[fd])) == NULL)
            return (-1);
        free(rest[fd]);
        rest[fd] = NULL;
        return (0);
    }
}