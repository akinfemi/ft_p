/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:04:57 by akinfemi          #+#    #+#             */
/*   Updated: 2018/02/05 11:05:01 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"
#include <errno.h>

int             get_port(int socket_fd)
{
    size_t      rd;
    char        buffer[1024];

    if((rd = recv(socket_fd, buffer, 1023, 0)) > 0)
    {
        buffer[rd] = '\0';
    }
    return (ft_atoi(buffer));
}

void        transfer_data(t_data *data)
{
    t_command   *cmd;
    int         fd;
    int         rd;
    char        buffer[BUFFER_SIZE];
    // char        *cwd;

    cmd = (t_command *)data->commands->content;
    if (!cmd->args || !cmd->args[1])
    {
        printf("Usage: put <filename>\n");
    }
    else
    {
        // cwd = getcwd(buffer, BUFF_SIZE);
        // sprintf(buffer, "%s/%s", cwd,cmd->args[1]);
        // printf("CWD: %s\n%s\n", buffer, cmd->args[1]);
        fd = open(cmd->args[1], O_RDONLY);
        while ((rd = read(fd, buffer, BUFFER_SIZE)))
        {
            buffer[rd] = '\0';
            // printf("Yello: {%s}\n", buffer);
            write(data->data_socket, buffer, rd);
            buffer[0] = '\0';
        }
        close(fd);
    }
}

int         handle_put(t_data *data)
{
    int                 port;
    int                 sd;
    struct sockaddr_in  addr;

    ft_memset(&addr, 0, sizeof(addr));
    if ((sd = send(data->as, "put\n", 4, 0x1)) > 0)
    {
        port = get_port(data->as);
        printf("Port: %d\n", port);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        data->data_socket = socket(PF_INET, SOCK_STREAM, 0);
        if (connect(data->data_socket, (const struct sockaddr *)&addr, sizeof(addr)) == -1)
            print_error(4);
        else
            printf("Data Connection Established\n");
        listen(data->data_socket, 1);
        transfer_data(data);
    }
    close(data->data_socket);
    return (1);
}