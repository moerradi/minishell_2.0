/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:23:48 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/09 04:18:29 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern char	**environ;

static size_t	calc_move(const char *string, size_t *size)
{
	size_t	nlen;
	size_t	r;
	char	*name;
	char	*eq;

	eq = ft_strchr(string, '=');
	name = ft_strndup(string, eq - string);
	nlen = ft_strlen(name);
	*size = 0;
	r = 0;
	while (environ[r] != NULL)
	{
		if (!ft_strncmp (environ[r], name, nlen) && environ[r][nlen] == '=')
			break ;
		else
			(*size)++;
		r++;
	}
	free(name);
	return (r);
}

static void	create_new_env(size_t size)
{
	static char	**last_env = NULL;
	char		**new_env;

	new_env = (char **) malloc(sizeof(char *) * (size + 2));
	if (last_env)
	{
		ft_memcpy((char *)new_env, (char *)last_env, size * sizeof(char *));
		free(last_env);
	}
	else
		ft_memcpy((char *) new_env, (char *)environ, size * sizeof(char *));
	new_env[size] = NULL;
	new_env[size + 1] = NULL;
	environ = new_env;
	last_env = environ;
}

int	ft_putenv(char const *string)
{
	char		**ep;
	size_t		size;
	size_t		move;
	char		*np;

	ep = environ;
	move = calc_move(string, &size);
	ep += move;
	if (*ep == NULL)
	{
		create_new_env(size);
		ep = environ + size;
	}
	np = ft_strdup(string);
	*ep = np;
	return (0);
}
