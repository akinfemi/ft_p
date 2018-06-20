/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_handles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:39:16 by akinfemi          #+#    #+#             */
/*   Updated: 2017/11/16 19:39:01 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

t_data			*init_cl_data(int accepted_socket)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->as = accepted_socket;
	getcwd(data->home, PATH_MAX);
	data->home_len = ft_strlen(data->home);
	data->p_stack = NULL;
	data->commands = NULL;
	data->u_input = NULL;
	return (data);
}

int         handle_lcd(t_data *data)
{
    t_command   *cmd;

    cmd = (t_command *)data->commands->content;
    if (!cmd->args || !cmd->args[1])
    {
        chdir(data->home);
        dprintf(data->as, "%s\n", "lcd : SUCCESS");
    }
    else
    {
        if(opendir(cmd->args[1]))
        {
            chdir(cmd->args[1]);
            dprintf(data->as, "%s\n", "lcd : SUCCESS");
        }
        else
        {
            dprintf(data->as, "%s\n", "lcd : ERROR");
        }
    }
    return (1);
}

int     handle_lls(t_data *data)
{
    pid_t           pid;
    int             status;
    t_command       *cmd;

    if ((pid = fork()) == 0)
    {
        cmd = (t_command *)data->commands->content;
        execv("/bin/ls", cmd->args);
    }
    while ((pid == wait(&status)) > 0)
        ;
    return (1);
}

char        *cl_commands[] =
{
    "lls",
    "lcd",
    "lpwd"
};

int     (*cl_cmds[]) (t_data *data) = 
{
    &handle_lls,
    &handle_lcd,
    &handle_path,
};

int     dispatch(t_data *data)
{
    int         i;
    int         len;
    t_command   *command;

    i = 0;
    command = (t_command *)data->commands->content;
    len = sizeof(cl_commands) / sizeof(char *);
    while (i < len)
    {
        if (ft_strcmp(cl_commands[i], command->bin) == 0)
        {
            return ((*cl_cmds[i])(data));
        }
        i++;
    }
    return (-1);
}

int         client_handles(char *buffer, t_data *data)
{
    t_list  *tokens;

    tokens = ft_lexer(ft_strtrim(buffer));
    data->commands = ft_parser(tokens);
    return (dispatch(data));
}