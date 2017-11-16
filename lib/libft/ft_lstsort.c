/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:34:30 by aakin-al          #+#    #+#             */
/*   Updated: 2017/11/02 23:06:10 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		lst_swap_contents(t_list *p1, t_list *p2)
{
	void		*tmp;

	tmp = p1->content;
	p1->content = p2->content;
	p2->content = tmp;
}

void			ft_lstsort(t_list *start, int (*f)(void *, void *, int), int r)
{
	int			swapped;
	t_list		*left;
	t_list		*right;

	right = NULL;
	if (start == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		left = start;
		while (left->next != right)
		{
			if (f(left->content, left->next->content, r))
			{
				lst_swap_contents(left, left->next);
				swapped = 1;
			}
			left = left->next;
		}
		right = left;
	}
}
