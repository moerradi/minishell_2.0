/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiktok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 01:49:24 by moerradi          #+#    #+#             */
/*   Updated: 2021/12/21 01:52:09 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int main()
{
	char *test = strdup("Hello >wop > dqod");
	char *token = strtok(test, "> ");
		printf("%s\n", token);
	while (token = strtok(NULL, "> "))
	{
		printf("%s\n", token);
	}
}