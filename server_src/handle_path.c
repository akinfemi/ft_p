/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:00:01 by akinfemi          #+#    #+#             */
/*   Updated: 2018/01/19 13:00:02 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

void        path_strjoin(t_data *data, char *str)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while(data->path[i])
        i++;
    while (str[j] != '\0' && i < PATH_MAX)
    {
        data->path[i] = str[j];
        j++;
        i++;
    }
    // free(str);
}

static void set_path(t_data *data)
{
    int     i;
    char    buf[PATH_MAX];

    i = 0;
    getcwd(buf, PATH_MAX);
    if (ft_strcmp(data->home, (char *)buf) == 0
        || ft_strncmp(data->home, (char *)buf, data->home_len) != 0)
        return ;
    while (data->home[i] == buf[i])
        i++;
    path_strjoin(data, ft_strsub((char *)buf, i, ft_strlen((char *)buf)));
}

int         handle_path(t_data *data)
{
    set_path(data);
    dprintf(data->as,"%s\n", data->path);
    return (1);
}