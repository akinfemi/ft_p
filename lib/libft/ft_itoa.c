/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:17:11 by exam              #+#    #+#             */
/*   Updated: 2017/03/08 23:47:31 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_length(long nb)
{
	if (nb < 0)
		return (1 + get_length(nb * (-1)));
	else if (nb < 10)
		return (1);
	else
		return (1 + get_length(nb / 10));
}

char			*ft_itoa(int nbr)
{
	char	*res;
	int		len;
	int		i;
	long	nb;

	nb = nbr;
	len = get_length(nb);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (0);
	i = len;
	res[len] = '\0';
	len--;
	if (nb < 0)
		nb *= -1;
	while (len >= 0)
	{
		res[len] = nb % 10 + '0';
		len--;
		nb /= 10;
	}
	if (res[0] == '0' && i > 1)
		res[0] = '-';
	return (res);
}
