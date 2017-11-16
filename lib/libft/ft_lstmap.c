/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:19:36 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/22 17:05:27 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*res;
	t_list	*tmp;

	if (!lst)
		return (lst);
	node = lst;
	tmp = f(ft_lstnew(node->content, node->content_size));
	res = tmp;
	while (node->next)
	{
		node = node->next;
		tmp->next = f(ft_lstnew(node->content, node->content_size));
		tmp = tmp->next;
	}
	return (res);
}
