/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:20:59 by moerradi          #+#    #+#             */
/*   Updated: 2022/01/06 21:23:49 by kdrissi-         ###   ########.fr       */
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
	test();
}
