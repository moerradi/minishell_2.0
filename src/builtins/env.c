/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:52:04 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/12/14 23:43:18 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// int     main(int ac, char **av, char **env)
// {
//     int i = 0;
//     while(env[i] != NULL)
//     {
//         printf("%s\n", env[i]);
//         i++;
//     }
// }

int	env(char **envs)
{
	t_dict *env;

	env = mdict_new(envs);
	// mdict_print(env);
	// mdict_destroy(&env);
}

int main(int ac, char **av, char **environ)
{
	char *answer;
	t_dict *env;

	env = mdict_new(environ);
	answer = mdict_lookup(env, av[1]);
	printf("%s = %s\n", av[1], answer);
}
