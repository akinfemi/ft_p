/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:07:16 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/08 22:07:59 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ch;
	unsigned char	*sr;

	i = 0;
	ch = dest;
	sr = (unsigned char *)src;
	while (i < n)
	{
		ch[i] = sr[i];
		i++;
	}
	return (dest);
}
