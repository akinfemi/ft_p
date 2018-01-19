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
    t_list  *temp;

    while (data->commands)
    {
        temp = data->commands;
        dispatch(data);
        data->commands = data->commands->next;
        // ft_lstdelone(temp, del);
    }
}

int         handle_ls(t_data *data)
{
    pid_t           pid;
    int             status;
    struct rusage   *rusage;
    t_command       *cmd;

    rusage = NULL;
    if ((pid = fork()) == 0)
    {
        dup2(data->as, 1);
        cmd = (t_command *)data->commands->content;
        execv("/bin/ls", cmd->args);
    }
    while (!WIFEXITED(status) && !WIFSIGNALED(status))
    {
        pid = wait4(pid, &status, WUNTRACED, rusage);
    }
    return (1);
}

int         handle_cd(t_data *data)
{
    // if (!dest)
    // {
    //     if ((pid = fork()) == 0)
    //     {
    //         // dup2(socket_fd, 1);
    //         // // getcwd(buf, PATH_MAX);
    //         // printf("%s\n", buf);
    //     }
    // }
    // else 
    // {
    //     if ((pid = fork()) == 0)
    //     {
    //         dup2(socket_fd, 1);
    //         // getcwd(buf, PATH_MAX);
    //         printf("%s\n", buf);
    //     }
    // }
    (void) data;
    return (1);
}