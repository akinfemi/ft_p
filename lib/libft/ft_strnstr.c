/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:02:32 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/08 21:58:09 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	contains(const char *big, const char *small, size_t n)
{
	while (*big && *small && (*big == *small) && n-- > 0)
	{
		big++;
		small++;
		if (*small == '\0')
			return (1);
	}
	return (0);
}

char		*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	if (*little == '\0')
		return ((char *)big);
	while (*big && *little && i < n)
	{
		if (*big == *little && contains(big, little, n - i) == 1)
			return ((char *)big);
		big++;
		i++;
	}
	return (ptr);
}
