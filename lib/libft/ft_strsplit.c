/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 20:59:15 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/26 09:34:22 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_nwords(char const *str, char delim)
{
	int	i;

	while (str && *str == delim)
		str++;
	i = (*str != '\0');
	while (*str)
	{
		if ((*str == delim) && (*(str + 1) != delim) && *(str + 1) != '\0')
			i++;
		str++;
	}
	return (i);
}

static char		*next_word(char const **st, char delim)
{
	int			i;
	char const	*str;
	char		*word;
	int			j;

	i = 0;
	j = 0;
	word = 0;
	str = *st;
	while (str && *str == delim)
		str++;
	while (str[i] != delim && str[i])
		i++;
	word = (char *)malloc(sizeof(char) * i + 1);
	while (*str != delim && str[i])
	{
		word[j] = *str;
		j++;
		str++;
	}
	word[j] = '\0';
	*st = str;
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ans;
	int		n_words;
	int		i;

	if (!s)
		return (0);
	n_words = get_nwords(s, c);
	ans = 0;
	i = 0;
	ans = (char **)malloc(sizeof(char *) * n_words + 1);
	if (ans == NULL)
		return (ans);
	while (i < n_words)
	{
		ans[i] = next_word(&s, c);
		i++;
	}
	ans[i] = 0;
	return (ans);
}
