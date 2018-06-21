/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:04:57 by akinfemi          #+#    #+#             */
/*   Updated: 2018/02/05 11:05:01 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"
#include <errno.h>

int         file_exist_wo_stat(char *path)
{
    int     fd;

    fd = open(path, O_RDONLY);
    if (fd > 1)
    {
        close(fd);
        return (1);
    }
    return (0);
}

static int        get_data(t_data *data)
{
    t_command   *cmd;
    int         fd;
    int         rd;
    char        buffer[1024];

    cmd = (t_command *) data->commands->content;
    if (cmd->args && file_exist_wo_stat(cmd->args[1]))
    {
        printf("Exists error\n");
        return (1);
    }
    else
    {
        fd = open(cmd->args[1], O_WRONLY | O_CREAT, 0777);
    }
    if (fd == -1)
    {
        printf("Open error\n");
        return (1);
    }
    printf("Stuck on read from %d\n", data->data_socket);
    while((rd = read(data->data_socket, buffer, 1023)) > 0)
    {
        buffer[rd] = '\0';
        write(fd, buffer, rd);
    }
    printf("FILE: %s Status: %s\n", cmd->args[1], "Transfer complete");
    close(fd);
    return (1);
}

int         handle_get(t_data *data)
{
    int                 port;
    int                 sd;
    struct sockaddr_in  addr;

    ft_memset(&addr, 0, sizeof(addr));
    if ((sd = write(data->cmd_as, data->u_input, ft_strlen(data->u_input))) > 0)
    {
        port = get_port(data->cmd_as);
        printf("Port: %d\n", port);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        printf("IP: %s\n", data->ip);
        addr.sin_addr.s_addr = inet_addr(data->ip);
        data->data_socket = socket(PF_INET, SOCK_STREAM, 0);
        if (connect(data->data_socket, (const struct sockaddr *)&addr, sizeof(addr)) == -1)
            print_error(4);
        else
            printf("Data Connection Established\n");
        // listen(data->data_socket, 1);
        get_data(data);
    }
    close(data->data_socket);
    return (1);
}