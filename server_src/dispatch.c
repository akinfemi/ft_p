/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:42:16 by akinfemi          #+#    #+#             */
/*   Updated: 2018/01/18 10:42:18 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

char        *ls_commands[] =
{
    "ls",
    "cd",
    "pwd",
    "quit",
    "put",
    "get"
};

int     (*ls_cmds[]) (t_data *data) = 
{
    &handle_ls,
    &handle_cd,
    &handle_path,
    &handle_quit,
    &handle_put,
    &handle_get,
    &handle_other
};

int     dispatch(t_data *data)
{
    int         i;
    int         len;
    t_command   *command;

    i = 0;
    command = (t_command *)data->commands->content;
    len = sizeof(ls_commands) / sizeof(char *);
    while (i < len)
    {
        if (ft_strcmp(ls_commands[i], command->bin) == 0)
        {
            printf("OO: %s -- %s\n", command->bin, command->args[1]);
            return ((*ls_cmds[i])(data));
        }
        i++;
    }
    return ((*ls_cmds[i])(data));
}