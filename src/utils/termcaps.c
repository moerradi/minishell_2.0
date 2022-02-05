/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:01:40 by moerradi          #+#    #+#             */
/*   Updated: 2022/02/05 18:59:20 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_putchar_int(int c)
{
	write(1, &c, 1);
	return (0);
}

void	reset_terminal(void)
{
	struct termios	new;

	tcgetattr(STDIN_FILENO, &new);
	new.c_iflag = 27394;
	new.c_oflag = 3;
	new.c_cflag = 19200;
	new.c_lflag = 536872399;
	new.c_lflag &= ~ECHOCTL;
	new.c_ispeed = 38400;
	new.c_ospeed = 38400;
	if (ft_atoi(ft_getenv("-screen")))
		tputs(tgetstr("te", NULL), 0, ft_putchar_int);
	tcsetattr(STDIN_FILENO, TCSANOW, &new);
}
