/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 17:25:29 by aakin-al          #+#    #+#             */
/*   Updated: 2017/11/02 23:11:53 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_bin(uintmax_t val)
{
	int8_t		len;
	char		*str;

	len = 8;
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	if (val == 0)
	{
		while (--len >= 0)
			str[len] = '0';
		return (str);
	}
	while (--len >= 0)
	{
		str[len] = (val % 2) + '0';
		val /= 2;
	}
	return (str);
}
