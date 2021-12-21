/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 03:55:24 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/12/21 04:04:33 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     words(char *str, char *set)
{
    int     i;
    int     wc;
    int     len;

    i = 0;
    wc = 0;
    // len = ft_strlen()

    while (str[i])
    {
        if (ft_strchr(set, str[i]) && str[i == str[i + 1]])
        {
            wc++;
            i = i + 2;
        }
        else if (ft_strchr(set, str[i]))
        {
            wc++;
            i++;
        }
        else
        {
            while (!ft_strchr(set, str[i]))
            {
                i++;
            }
            wc++;
        }
    }
    
}