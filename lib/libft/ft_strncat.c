/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:22:11 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/08 22:23:00 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dst[i] != '\0')
	{
		i++;
	}
	while (*src && size > 0)
	{
		dst[i] = *src;
		src++;
		size--;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
