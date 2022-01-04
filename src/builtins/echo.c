/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:20:30 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/03 17:58:55 by kdrissi-         ###   ########.fr       */
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

// int	echo(t_list *args, int ac)
// {
// 	int	i;
// 	t_list *tmp;

// 	i = 0;
// 	tmp  = args;
// 	if (!ft_strcmp((char *)args->content, "-n"))
// 		args = args->next;
// 	while (args != NULL)
// 	{
// 		printf("%s ", args->content);
// 		args = args->next;
// 	}
// 	if (ft_strcmp((char *)tmp->content, "-n"))
// 		printf("\n");
// }
