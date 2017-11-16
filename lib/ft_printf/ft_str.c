/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 23:12:07 by aakin-al          #+#    #+#             */
/*   Updated: 2017/06/19 23:12:42 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_padstr(char ch, int len)
{
	char	*res;
	int		i;

	if (len < 0)
		len = 0;
	res = (char *)ft_memalloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < len)
		res[i] = ch;
	return (res);
}
