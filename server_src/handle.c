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
#include <errno.h>

int         handle_get(t_data *data)
{
    (void)data;
    return (1);
}

int         file_exist(char *filename)
{
    int     fd;

    fd = open(filename, O_RDONLY);
    if (fd > 1)
    {
        close(fd);
        return (1);
    }
    return (0);
}

void        receive_data(t_data *data)
{
    struct  stat file_stat;
    t_command   *cmd;
    int         fd;

    cmd = (t_command *) data->commands->content;
    if (!file_exist(cmd->args[1]))
    {
        fd = open(cmd->args[1], O_WRONLY)
    }
    // if(fstat(cmd->args[1]) == -1)
    // {
    //     printf("File doesn't exist, create, read from socket and write to file");
    // }
    // else
    // {
    //     printf("File already exists");
    // }
}

int         handle_put(t_data *data)
{
    struct      sockaddr_in addr;
    socklen_t   addr_len;

    addr.sin_family = AF_INET;
    addr.sin_port = 0; //to bind to any available port
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    data->data_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (bind(data->data_socket, (const struct sockaddr *)&addr, sizeof(addr)) == -1)
        perror(strerror(errno));
    listen(data->data_socket, 1);
    addr_len = sizeof(addr);
    if(getsockname(data->data_socket, (struct sockaddr *)&addr, &addr_len) == -1)
        print_error(2);
    dprintf(data->as, "%d", addr.sin_port);
    while (1)
    {
        data->data_as = accept(data->data_socket, (struct sockaddr *)&addr, &addr_len);
        if (data->data_as == -1)
            print_error(3);
        receive_data(data);
    }
    close(data->data_as);
    close(data->data_socket);
    return (1);
}