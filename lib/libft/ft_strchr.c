/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:57:04 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/08 21:32:59 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strchr(const char *s, int c)
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
		{
			ptr = (char *)s;
			return (ptr);
		}
		s++;
	}
	return (ptr);
}
