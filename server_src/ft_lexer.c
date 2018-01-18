/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 12:46:16 by akinfemi          #+#    #+#             */
/*   Updated: 2017/12/21 12:46:29 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

t_list      *ft_lexer(char *input)
{
    char    **words;

    words = sh_strsplit(input);
    return(ft_tokenize(words));
}