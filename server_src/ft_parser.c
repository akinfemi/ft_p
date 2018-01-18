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

#include "../include/ftp.h"

static char     **get_args(t_list **alst, int *type)
{
    char        **res;
    int         size;
    t_token     *token;
    t_list      *list;
    int         i;

    size = INIT_SIZE;
    list = *alst;
    i = 0;
    res = (char **)ft_memalloc(sizeof(char *) * size);
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

t_list          *ft_parser(t_list *tokens)
{
    t_list      *commands;
    t_exec      *command;
    t_token     *token;
    int         type;

    commands = NULL;
    while (tokens)
    {
        token = tokens->content;
        command = (t_exec *)malloc(sizeof(t_exec));
        command->bin = token->word;
        command->args = NULL;
        if (token->type == WORD){
            tokens = tokens->next;
            command->args = get_args(&tokens, &type);
            command->chain = type;
            ft_lstappend(&commands, ft_lstnew(command, sizeof(command)));
            continue;
        }
        command->chain = token->type;
        ft_lstappend(&commands, ft_lstnew(command, sizeof(command)));
        tokens = tokens->next;
    }
    int i = 0;
    while (commands)
    {
        command = commands->content;
        if (!command->args)
        {
            commands = commands->next;
            printf("NUULL\n");
            continue;
        }
        while(command->args[i])
        {
            printf("Arg[%d] = %s\n", i, command->args[i]);
            i++;
        }
        commands = commands->next;
    }
    // return (commands);
    return (0);
}