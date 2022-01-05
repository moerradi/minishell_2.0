/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:20:30 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/04 21:04:47 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	echo(char **args, int ac)
{
	int	i;

	i = 0;
	if (!ft_strcmp(args[0], "-n"))
		i++;
	while (i < ac - 1)
		printf("%s ", args[i++]);
	printf("%s", args[i]);
	if (!ft_strcmp(args[0], "-n"))
		printf("\n");
}
