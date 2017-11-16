/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 23:03:43 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/08 22:07:26 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ds;
	unsigned char	*sc;

	ds = (unsigned char *)dst;
	sc = (unsigned char *)src;
	if (sc < ds)
	{
		while (len-- > 0)
			ds[len] = sc[len];
	}
	else
		ft_memcpy(ds, sc, len);
	return (ds);
}
