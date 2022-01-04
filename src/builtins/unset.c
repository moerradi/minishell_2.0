/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:09:08 by kdrissi-          #+#    #+#             */
/*   Updated: 2022/01/03 18:23:43 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int     unset(char **args, int ac)
{
    int i;

    i = 0;
    while (args[i])
        mdict_remove_node(g_env, args[i++]);
}

int     unset(t_list    *args)
{
    t_list *tmp;

    tmp = args;
    while (tmp)
    {
        mdict_remove_node(g_env, (char *)tmp->content);
        tmp = tmp->next;
    }
}
