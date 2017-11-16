/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 21:33:54 by aakin-al          #+#    #+#             */
/*   Updated: 2017/04/06 01:33:40 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	long	ans;
	int		sign;

	ans = 0;
	sign = 1;
	while ((*nptr == ' ') || (*nptr == '\t') || (*nptr == '\n')
		|| (*nptr == '\v') || (*nptr == '\f') || (*nptr == '\r'))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		ans = ans * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(sign * ans));
}
