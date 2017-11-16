/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:49:46 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/22 17:04:10 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*tmp;

	node = *alst;
	while (node)
	{
		del(node->content, node->content_size);
		tmp = node;
		node = node->next;
		free(tmp);
	}
	*alst = NULL;
}
