/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:04 by moerradi          #+#    #+#             */
/*   Updated: 2019/10/11 02:08:53 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	last;
	unsigned int	temp;

	temp = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		temp = -n;
	}
	if (temp >= 10)
	{
		last = temp % 10;
		ft_putnbr_fd(temp / 10, fd);
		ft_putchar_fd(last + 48, fd);
	}
	else
		ft_putchar_fd(temp + 48, fd);
}
