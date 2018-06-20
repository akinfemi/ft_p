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

static int  new_socket_connection(t_data *data)
{
    int         accepted_socket = 0;
    struct      sockaddr_in addr;
    socklen_t   addr_len;
    char        *port_addr;

    addr.sin_family = AF_INET;
    addr.sin_port = 0; //to bind to any available port
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(data->data_socket, (const struct sockaddr *)&addr, sizeof(addr)) == -1)
        perror(strerror(errno));
    listen(data->data_socket, 1);
    addr_len = sizeof(addr);
    if (getsockname(data->data_socket, (struct sockaddr *)&addr, &addr_len) == -1)
        print_error(2);
    else
    {
        port_addr = ft_itoa(ntohs(addr.sin_port));
        printf("Port: {%s}\n", port_addr);
        write(data->as, port_addr, ft_strlen(port_addr));
        accepted_socket = accept(data->data_socket, (struct sockaddr *)&addr, &addr_len);
        printf("connection accepted\n");
        free(port_addr);
    }
    return (accepted_socket);
}

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

static int send_data(t_data *data)
{
    t_command   *cmd;
    int         fd;
    int         rd;
    char        buffer[1024];

    cmd = (t_command *) data->commands->content;
    if (cmd->args && file_exist_wo_stat(cmd->args[1]))
        fd = open(cmd->args[1], O_RDONLY);
    else
    {
        write(data->as, "File doesn't exist\n", 19);
        return (0);
    }
    if (fd == -1)
    {
        write(data->as, "File cannot be read\n", 20);
        return (0);
    }
    while((rd = read(fd, buffer, 1023)) > 0)
    {
        buffer[rd] = '\0';
        write(data->data_as, buffer, rd);
    }
    close(fd);
    return (1);
}

int         handle_get(t_data *data)
{
    data->data_socket = socket(PF_INET, SOCK_STREAM, 0);
    data->data_as = new_socket_connection(data);
    printf("New connection established\n");
    if (data->data_as == -1)
        print_error(3);
    send_data(data);
    close(data->data_as);
    close(data->data_socket);
    return (1);
}

static int receive_data(t_data *data)
{
    t_command   *cmd;
    int         fd;
    int         rd;
    char        buffer[1024];

    cmd = (t_command *) data->commands->content;
    if (cmd->args && file_exist_wo_stat(cmd->args[1]))
        fd = open(cmd->args[1], O_WRONLY);
    else
    {
        write(data->as, "File exists by that name on server\n", 25);
        printf("Reciveing data to: %s -> bin %s\n", cmd->bin,cmd->args[1]);
        return (0);
    }
    while((rd = read(data->data_as, buffer, 1023)) > 0)
    {
        buffer[rd] = '\0';
        write(fd, buffer, rd);
    }
    close(fd);
    return (1);
}

int         handle_put(t_data *data)
{
    data->data_socket = socket(PF_INET, SOCK_STREAM, 0);
    data->data_as = new_socket_connection(data);
    printf("New connection established\n");
    if (data->data_as == -1)
        print_error(3);
    receive_data(data);
    close(data->data_as);
    close(data->data_socket);
    return (1);
}