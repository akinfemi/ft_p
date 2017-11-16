/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:05:09 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/22 15:36:26 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		res;
	size_t		dl;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size + ft_strlen(src) > ft_strlen(src) + ft_strlen(dst))
		res = ft_strlen(src) + ft_strlen(dst);
	else
		res = ft_strlen(src) + size;
	dl = ft_strlen(dst);
	if (dl < size - 1 && size != 0)
	{
		while (*dst)
		{
			dst++;
			i++;
		}
		while (*src && i++ < size - 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (res);
}
