/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:22:33 by aakin-al          #+#    #+#             */
/*   Updated: 2017/09/01 14:28:51 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	int		len;
	int		i;

	if (!str)
		return (0);
	i = -1;
	len = ft_strlen(str);
	while (++i < len)
		str[i] = ft_tolower(str[i]);
	str[len] = '\0';
	return (str);
}
