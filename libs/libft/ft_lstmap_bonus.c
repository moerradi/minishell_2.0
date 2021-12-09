/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:17:18 by moerradi          #+#    #+#             */
/*   Updated: 2019/10/11 22:17:20 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*node;
	void	*ptr;

	if (!f || !lst)
		return (NULL);
	ptr = (*f)(lst->content);
	node = ft_lstnew(ptr);
	if (!node)
		return (NULL);
	out = node;
	while (lst->next)
	{
		lst = lst->next;
		ptr = (*f)(lst->content);
		node->next = ft_lstnew(ptr);
		if (!node->next)
		{
			ft_lstclear(&out, del);
			return (NULL);
		}
		node = node->next;
	}
	return (out);
}
