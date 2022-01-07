/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:23:48 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/06 21:29:14 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern char **environ;

int	ft_putenv(const char *string)
{
	static char	**last_env = NULL;
	char	**ep;
	char	**new_env;
	size_t	namelen;
	size_t	size;
	char	*name;

	name = ft_strndup(string, ft_strchr(string, '=') - string);
	namelen = ft_strlen(name);
	ep = environ;
	size = 0;
	while (*ep != NULL)
	{
		if (!ft_strncmp (*ep, name, namelen) && (*ep)[namelen] == '=')
			break;
		else
			size++;
		++ep;
	}
	if (*ep == NULL)
	{
		new_env = (char **) malloc(sizeof(char *) * (size + 2));
		if (last_env)
		{
			ft_memcpy((char *) new_env, (char *) last_env, size * sizeof (char *));
			free(last_env);
		}
		else
			ft_memcpy((char *) new_env, (char *) environ, size * sizeof (char *));
		new_env[size] = NULL;
		new_env[size + 1] = NULL;
		ep = new_env + size;
		environ = new_env;
		last_env = environ;
	}
	free(name);
	char *np;
	np = (char *) string;
	*ep = np;
	return 0;
}