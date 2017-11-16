/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 21:30:50 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/08 21:32:10 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = 0;
	i = -1;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (str);
	while (++i <= size)
		str[i] = '\0';
	return (str);
}
