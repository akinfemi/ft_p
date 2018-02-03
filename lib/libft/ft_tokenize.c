/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:32:57 by akinfemi          #+#    #+#             */
/*   Updated: 2017/12/21 13:32:58 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list          *new_token(char *word, int type)
{
    t_token     *token;

    token = (t_token *)malloc(sizeof(t_token));
    if (!token)
        return (0);
    token->word = word;
    token->type = type;
    return (ft_lstnew(token, sizeof(token)));
}

int             get_token_type(char **word)
{
    int         len;

    if (!word || !*word)
        return (-1);
    len = ft_strlen(*word);
    if (word[0][len - 1] == ';')
    {
        word[0][len - 1] = '\0';
        return (CHAIN);
    }
    return (WORD);
}

t_list         *ft_tokenize(char **words)
{
    int         type;
    t_list      *token_list;
    int         i;

    type = -1;
    i = 0;
    token_list = NULL;
    while (words[i])
    {
        type = get_token_type(&words[i]);
        if (type != -1)
            ft_lstappend(&token_list, new_token(words[i], type));
        i++;
    }
    return(token_list);
}