/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 01:15:10 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/10 22:09:00 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	set_exit(int status)
{
	char	*toput;
	char	*num;

	num = ft_itoa(status);
	printf("num : %s %i\n", num, status);
	
	toput = ft_strjoin("?=", num);
	free(num);
	ft_putenv(toput);
	free(toput);
}
