/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:07:46 by moerradi          #+#    #+#             */
/*   Updated: 2021/12/30 19:47:31 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_dict	*g_env;

char	*expand(char *key)
{
	char *out;

	out = mdict_key_search(g_env, key);
	if (!out)
		return ("");
	return (out);
}
