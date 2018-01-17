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

void        handle_command(t_data *data)
{
    printf("%s", data->u_input); // verify reciept of info
    if (ft_strcmp(data->u_input, "ls") == 0)
        handle_ls(data);
    else if (ft_strcmp(data->u_input, "cd") == 0)
        handle_cd(data);
    else if (ft_strcmp(data->u_input, "get") == 0)
        handle_get(data);
    else if (ft_strcmp(data->u_input, "put") == 0)
        handle_put(data);
    else if (ft_strcmp(data->u_input, "pwd") == 0)
        handle_path(data);
    else if (ft_strcmp(data->u_input, "quit") == 0)
        handle_quit(data);
    else
        handle_other(data);
}

void        handle_ls(t_data *data)
{
    int     pid;

    if ((pid = fork()) == 0)
    {
        dup2(data->as, 1);
        execl("/bin/ls", "ls", "-l", (char *)NULL);
    }
}

void        handle_cd(t_data *data)
{
    // if (!dest)
    // {
    //     if ((pid = fork()) == 0)
    //     {
    //         // dup2(socket_fd, 1);
    //         // // getcwd(buf, MAXPATHLEN);
    //         // printf("%s\n", buf);
    //     }
    // }
    // else 
    // {
    //     if ((pid = fork()) == 0)
    //     {
    //         dup2(socket_fd, 1);
    //         // getcwd(buf, MAXPATHLEN);
    //         printf("%s\n", buf);
    //     }
    // }
    (void)data;
}

void        handle_path(t_data *data)
{
    char    buf[MAXPATHLEN];
    int     pid;

    if ((pid = fork()) == 0)
    {
        dup2(data->as, 1); //redirect stdout to file
        getcwd(buf, MAXPATHLEN);
        ft_printf("%s\n", buf);
    }
}