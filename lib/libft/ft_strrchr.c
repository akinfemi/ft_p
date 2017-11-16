/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:20:00 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/08 22:08:26 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	nc;
	char	*ptr;

	nc = (char)c;
	ptr = 0;
	if (nc == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == nc)
			ptr = (char *)s;
		s++;
	}
	return (ptr);
}
