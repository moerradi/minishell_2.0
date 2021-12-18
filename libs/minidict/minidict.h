/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minidict.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:57:38 by moerradi          #+#    #+#             */
/*   Updated: 2021/12/16 14:15:56 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIDICT_H
# define MINIDICT_H
# include "../libft/libft.h"

typedef struct s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
}					t_dict;

void	mdict_addback(t_dict **dict, t_dict *new);
t_dict	*mdict_new(char *key, char *value); // allocate for one node;
t_dict	*mdict_fill(char **env); // create list of key value from char **
void	mdict_destroy(t_dict **dict);
void	mdict_print(t_dict *dict);
void	mdict_insert(t_dict **dict, char *key, char *value);
char	*mdict_key_search(t_dict *dict, char *key);
void	mdict_remove_node(t_dict **dict, char *key);
t_dict	*mdict_node_search(t_dict *dict, char *key);
void	mdict_delone(t_dict **dict);
#endif