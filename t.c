/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:20:59 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/06 21:30:41 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// extern char	**environ;
#include <stdlib.h>
#include <stdio.h>
extern char **environ;

int	ft_putenv(const char *string);

void	test();
int	main(int ac, char **av)
{
	ft_putenv(av[1]);
	int i = 0;
	while (environ[i])
		printf("%s\n", environ[i++]);
}
