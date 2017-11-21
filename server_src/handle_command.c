/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:39:16 by akinfemi          #+#    #+#             */
/*   Updated: 2017/11/16 19:39:01 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

void        handle_command(int sockt, char *buffer)
{
    printf("%s",buffer); // verify reciept of info
    if (ft_strcmp(buffer, "ls\n") == 0)
        handle_ls(sockt, "\0");
    else if (ft_strcmp(buffer, "cd\n") == 0)
        handle_cd(sockt, "\0");
    else if (ft_strcmp(buffer, "get\n") == 0)
        handle_get(sockt, "\0");
    else if (ft_strcmp(buffer, "put\n") == 0)
        handle_put(sockt, "\0", "\0");
    else if (ft_strcmp(buffer, "pwd\n") == 0)
        handle_path(sockt);
    else if (ft_strcmp(buffer, "quit\n") == 0)
        handle_quit(sockt);
    else
        handle_other(sockt, buffer);
}

void        handle_ls(int socket_fd, char *flags)
{
    (void)flags;
    execl("/bin/ls", ">", "out.tmp");
    read_and_send(socket_fd, "out.tmp");
}

void        handle_cd(int socket_fd, char *dest)
{
    (void)socket_fd;
    (void)dest;
}

void        handle_path(int socket_fd)
{
    (void)socket_fd;
}