/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minidict.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:57:38 by moerradi          #+#    #+#             */
/*   Updated: 2021/12/09 15:01:43 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIDICT_H
# define MINIDICT_H
# include "../libft/libft.h"

typedef struct		s_dict
{
	char	*key;
	char	*value;
	struct	s_dict *next;
}					t_dict;

t_dict	*mdict_new();
char	*mdict_lookup(t_dict dict, char *key);

#endif