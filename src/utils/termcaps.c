/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:01:40 by moerradi          #+#    #+#             */
/*   Updated: 2022/02/06 19:32:53 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_putchar_int(int c)
{
	write(1, &c, 1);
	return (0);
}

int	termcmp(struct termios t1, struct termios t2)
{
	int i;
	int ret;

	ret = 0;
	if (t1.c_cflag != t2.c_cflag)
		return (1);
	if (t1.c_iflag != t2.c_iflag)
		return (1);
	if (t1.c_ispeed != t2.c_ispeed)
		return (1);
	if (t1.c_oflag != t2.c_oflag)
		return (1);
	if (t1.c_ospeed != t2.c_ospeed)
		return (1);
	i = 0;
	while (i < NCCS)
	{
		if (t1.c_cc[i] != t2.c_cc[i])
			return (1);
		i++;
	}
	return (ret);
}

void	reset_terminal(void)
{
	static bool		initiated = false;
	static struct	termios og;
	struct termios	new;

	if (!initiated)
	{
		tcgetattr(STDIN_FILENO, &og);
		og.c_lflag &= ~ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &og);	
		initiated = true;
		return ;
	}
	tcgetattr(STDIN_FILENO, &new);
	if (termcmp(og, new))
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &og);	
		// tputs(tgetstr("ti", NULL), 1, ft_putchar_int);
		// tputs(tgetstr("bl", NULL), 0, ft_putchar_int);
		// tputs(tgetstr("ve", NULL), 0, ft_putchar_int);	
		// tputs(tgetstr("rs", NULL), 0, ft_putchar_int);
	}
}
