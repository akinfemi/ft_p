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

    rusage = NULL;
    if ((pid = fork()) == 0)
    {
        dup2(data->as, 1);
        execl("/bin/ls", "ls", "-l", (char *)NULL);
    }
    while (!WIFEXITED(status) && !WIFSIGNALED(status))
    {
        pid = wait4(pid, &status, WUNTRACED ,rusage);
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
    (void) data;
    return (1);
}

// static void set_path(t_data *data, char buf[MAXPATHLEN])
// {
//     int     i;

//     i = 0;
//     if (ft_strcmp(data->home, (char *)buf) == 0
//         || ft_strncmp(data->home, (char *)buf, data->home_len) != 0)
//         return ;
//     while (data->home[i] == buf[i])
//         i++;
//     while (buf[i] || i == MAXPATHLEN)
//     {
//         data->path[i + 1] = buf[i];
//         i++;
//     }
// }

int         handle_path(t_data *data)
{
    char    buf[MAXPATHLEN];
    int     pid;

    if ((pid = fork()) == 0)
    {
        dup2(data->as, 1); //redirect stdout to file
        getcwd(buf, MAXPATHLEN);
        // set_path(data, buf);
        ft_printf("%s\n", data->path);
    }
    return (1);
}