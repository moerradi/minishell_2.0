/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:52:04 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/04 21:04:57 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

extern char	**environ;

int	env(void)
{
	int	i;

	i = 0;
	while (environ[i])
		{
			printf("%s\n", environ[i]);
			i++;
		}
	return (0);
}
