/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:28:36 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/01 21:22:11 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memset(void *str, int c, size_t n)
{
	unsigned char	ch;
	size_t			i;
	unsigned char	*ptr;

	ch = (unsigned char)c;
	ptr = str;
	i = -1;
	while (++i < n)
		ptr[i] = ch;
	return (str);
}
