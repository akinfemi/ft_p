/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 12:28:08 by akinfemi          #+#    #+#             */
/*   Updated: 2017/12/27 12:28:13 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char     **get_args(t_list **alst, int *type, char *bin)
{
    char        **res;
    int         size;
    t_token     *token;
    t_list      *list;
    int         i;

    size = INIT_SIZE;
    list = *alst;
    i = 1;
    res = (char **)ft_memalloc(sizeof(char *) * size);
    res[0] = bin;
    while (list && i < size)
    {
        if (i == size - 1)
        {
            size *= 2;
            res = (char **)ft_realloc(res, sizeof(char *) * (size / 2), sizeof(char *) * size);
        }
        token = list->content;
        res[i] = token->word;
        if (token->type == CHAIN)
        {
            *type = CHAIN;
            break;
        }
        list = list->next;
        i++;
    }
    *alst = list;
    return (res);
}
#include <stdio.h>
static void print_tokens(t_list *tokens)
{
    t_token *test;
    while(tokens)
    {
        test = tokens->content;
        printf("Tokes: %s\n", test->word);
        tokens = tokens->next;
    }
}

t_list          *ft_parser(t_list *tokens)
{
    t_list      *commands;
    t_command   *command;
    t_token     *token;
    int         type;

    commands = NULL;
    print_tokens(tokens);
    printf("Here tokens\n");
    while (tokens)
    {
        token = tokens->content;
        command = (t_command *)ft_memalloc(sizeof(t_command));
        command->bin = token->word;
        command->args = NULL;
        if (token->type == WORD){
            tokens = tokens->next;
            command->args = get_args(&tokens, &type, command->bin);
            command->chain = type;
            ft_lstappend(&commands, ft_lstnew(command, sizeof(command)));
            // printf("parser bin: %s\n", command->bin);
            continue;
        }
        // printf("Parser chain: %s\n");
        command->chain = token->type;
        ft_lstappend(&commands, ft_lstnew(command, sizeof(command)));
        tokens = tokens->next;
    }
    // int i = 0;
    // t_list *cm = commands;
    // while (cm)
    // {
    //     command = cm->content;
    //     if (!command->args)
    //     {
    //         cm = cm->next;
    //         printf("NUULL\n");
    //         continue;
    //     }
    //     while(command->args[i])
    //     {
    //         printf("Arg[%d] = %s\n", i, command->args[i]);
    //         i++;
    //     }
    //     printf("Command bins: %s\n", command->bin);
    //     cm = cm->next;
    // }
    printf("bye tokens\n");
    return (commands);
}