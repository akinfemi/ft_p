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

void        dispatch(t_command *command)
{
    (void)command;
}

/*
    if (ft_strcmp(command->bin, "ls") == 0)
    handle_ls(data);
    else if (ft_strcmp(command->bin, "cd") == 0)
    handle_cd(data);
    else if (ft_strcmp(command->bin, "get") == 0)
    handle_get(data);
    else if (ft_strcmp(command->bin, "put") == 0)
    handle_put(data);
    else if (ft_strcmp(command->bin, "pwd") == 0)
    handle_path(data);
    else if (ft_strcmp(command->bin, "quit") == 0)
    handle_quit(data);
    else
    handle_other(data);

typedef struct      s_command
{
    char            *bin;
    char            **flags;
    char            **args;
}                   t_command;
*/