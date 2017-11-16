/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atomax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 23:12:52 by aakin-al          #+#    #+#             */
/*   Updated: 2017/11/02 23:12:57 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t		ft_atomax(const char *nptr)
{
	intmax_t	ans;
	int			sign;

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
	return (sign * ans);
}
