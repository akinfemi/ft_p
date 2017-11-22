/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:39:16 by akinfemi          #+#    #+#             */
/*   Updated: 2017/11/16 19:39:01 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

void        handle_get(int socket_fd, char *filepath)
{
    (void)socket_fd;
    (void)filepath;
}

void        handle_put(int socket_fd, char *filepath, char *destination)
{
    (void)socket_fd;
    (void)filepath;
    (void)destination;
}

void        handle_quit(int socket_fd)
{
    printf("Closing client.\n");
    write(socket_fd, "Goodbye :) ...\n", 15);
    close(socket_fd);
}

void        handle_other(int sockt, char *buffer)
{
    buffer[ft_strlen(buffer) - 1] = '\0';
    dprintf(sockt, "%s is an Invalid Command\n", buffer);
}