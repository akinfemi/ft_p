/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:38:49 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/12 12:10:17 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_nwords(char const *str, char delim)
{
	int		i;

	while (*str == delim)
		str++;
	i = (*str != '\0');
	while (*str)
	{
		if ((*str == delim) && (*str + 1) != delim && *(str + 1) != '\0')
			i++;
		str++;
	}
	return (i);
}

static char		*next_word(char **st, char delim)
{
	int			i;
	char		*str;
	char		*word;
	int			j;

	i = 0;
	j = 0;
	word = 0;
	str = *st;
	while (*str == delim)
		str++;
	while (str[i] != delim)
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

t_list			*ft_strsplitlist(char *str, char delim)
{
	int		n_words;
	t_list	*list;
	t_list	*node;
	char	*word;

	n_words = get_nwords(str, delim);
	if (n_words > 0)
	{
		word = next_word(&str, delim);
		list = ft_lstnew(word, (size_t)ft_strlen(word));
		n_words--;
	}
	while (n_words-- > 0)
	{
		word = next_word(&str, delim);
		node = ft_lstnew(word, (size_t)ft_strlen(word));
		ft_lstappend(&list, node);
	}
	return (list);
}
