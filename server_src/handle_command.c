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
    t_command   *cmd;
    char        *temp_path;

    cmd = (t_command *)data->commands->content;
    if (!cmd->args || !cmd->args[1])
    {
        chdir(data->home);
        set_path(data, cmd->args);
        dprintf(data->as, "%s\n", "cd : SUCCESS");
    }
    else
    {
        set_path(data, cmd->args);
        temp_path = get_path(data);
        printf("temp path cd: %s\n", temp_path);
        if (chdir(temp_path) == 0)
        {
            dprintf(data->as, "%s\n", "cd : SUCCESS");
        }
        else
        {
            dprintf(data->as, "%s %s\n", "cd : ERROR", temp_path);
            pop(data->p_stack);
        }
        // free(temp_path);
    }
    return (1);
}

int         handle_quit(t_data *data)
{
    printf("Closing client.\n");
    write(data->as, "Goodbye :) ...\n", 15);
    //cleaning up client memory usage
    close(data->as);
    return (1);
}

int         handle_other(t_data *data)
{
    dprintf(data->as, "%s is an Invalid Command\n", data->u_input);
    return (1);
}