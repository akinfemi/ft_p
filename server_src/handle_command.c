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
    // if (ft_strcmp(buffer, "ls\n") == 0)
    //     write(sockt, (void *)buffer, ft_strlen(buffer));
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
    int     fd = 0;
    int     pid;
    int     stat_lc;
    struct  rusage usage_info;

    if ((pid = fork()) == 0)
    {
        fd = open(".out.tmp", O_RDWR | O_CREAT, 0666);
        dprintf(2, "before dup %d\n", fd);
        dup2(fd, 1); //redirected stdout to file
        flags = "-l";
        close(fd);
        execl("/bin/ls", "ls", flags, (char *)NULL);
        dprintf(2, "after dup %d\n", fd);
        read_and_send(socket_fd, ".out.tmp");
    }
    if (pid == wait4(pid, &stat_lc, WNOHANG, &usage_info))
    {
        dprintf(2,"child process complete %d", fd);
        // read_and_send(socket_fd, ".out.tmp");
    }
    // write(socket_fd, "buffer4\n", 8);
    //unlink("out.tmp");
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