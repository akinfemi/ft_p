/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:19:57 by akinfemi          #+#    #+#             */
/*   Updated: 2017/12/21 13:20:00 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int  ft_is_quote(char c)
{
    char    *delims;

    delims = "\"\'`";
    while (*delims)
    {
        if (c == *delims)
        {
            return (1);
        }
        delims++;
    }
    return (0);
}

static char *get_word(char **words)
{
    char    *res;
    char    *word;
    int     index;

    if (!words || !*words)
        return (0);
    index = 0;
    word = *words;
    while(word[index])
    {
        index++;
        if (ft_is_quote(word[index]) || word[index] == ' ')
            break;
    }
    res = ft_strndup(word, index);
    while (word[index] == ' ')
        index++;
    *words = *words + index;
    return (res);
}

char        *get_quote_word(char **words, char quote)
{
    char    *word;
    int     index;
    char    *res;

    if (!words || !*words)
        return (0);
    index = 0;
    *words = *words + 1;
    word = *words;
    while (word[index])
    {
        index++;
        if(word[index] == quote)
            break;
    }
    res = ft_strndup(word, index);
    while (word[index] == ' ' || word[index] == quote)
        index++;
    *words = *words + index;
    return (res);
}

char        **sh_strsplit(char *words)
{
    char    **res;
    char    *word;
    int     i;
    int     size;

    if (!words)
        return (0);
    i = 0;
    size = INIT_SIZE;
    res = (char **)ft_memalloc(sizeof(char *) * size);
    while (*words)
    {
        if (i == size - 1)
        {
            size *= 2;
            res = (char **)ft_realloc(res, sizeof(char *) * (size / 2), sizeof(char *) * size);
        }
        if (ft_is_quote(*words))
        {
            word = get_quote_word(&words, *words);
            res[i] = word;
        }
        else if (ft_isprint(*words) || *words == ' ')
        {
            word = get_word(&words);
            res[i] = word;
        }
        i++;
    }
    return (res);
}