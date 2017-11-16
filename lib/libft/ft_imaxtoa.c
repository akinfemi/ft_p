/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:17:11 by exam              #+#    #+#             */
/*   Updated: 2017/06/24 09:11:55 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_imaxtoa(uintmax_t value)
{
	uintmax_t	i;
	intmax_t	size;
	char		*ret;

	size = 1;
	i = value;
	while ((i /= 10))
		size++;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	i = value;
	ret[--size] = "0123456789"[i % 10];
	while ((i /= 10))
		ret[--size] = "0123456789"[i % 10];
	return (ret);
}
