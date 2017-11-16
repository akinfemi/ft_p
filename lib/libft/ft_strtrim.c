/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:48:52 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/08 19:48:43 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		w_len;
	char	*ans;
	int		i;

	ans = 0;
	i = -1;
	if (!s)
		return (0);
	while ((*s == ' ' || *s == '\t' || *s == '\n') && (*s))
		s++;
	w_len = ft_strlen(s);
	while (w_len != 0 && ((s[w_len - 1] != '\0')) && (s[w_len - 1] == ' '
				|| s[w_len - 1] == '\t' || s[w_len - 1] == '\n'))
		w_len--;
	ans = (char *)malloc(sizeof(char) * w_len + 1);
	if (!ans)
		return (0);
	while (*s && ++i < w_len && ans)
	{
		ans[i] = *s;
		s++;
	}
	ans[w_len] = '\0';
	return (ans);
}
