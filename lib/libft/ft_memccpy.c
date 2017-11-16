/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 22:30:30 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/22 15:20:37 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*sr;
	unsigned char	*ds;

	i = 0;
	ch = (unsigned char)c;
	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
		if (sr[i - 1] == ch)
		{
			ds += i;
			return ((void *)ds);
		}
	}
	return ((char *)0);
}
