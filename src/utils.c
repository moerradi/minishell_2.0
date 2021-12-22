/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:07:46 by moerradi          #+#    #+#             */
/*   Updated: 2021/12/20 21:31:04 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	print_pipes(char **pipes)
{
	int i;

	i = 0;
	while (pipes[i])
		printf("%s\n", pipes[i++]);
}