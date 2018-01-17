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

void        handle_get(t_data *data)
{
    (void)data;
}

void        handle_put(t_data *data)
{
    (void)data;
}

void        handle_quit(t_data *data)
{
    printf("Closing client.\n");
    write(data->as, "Goodbye :) ...\n", 15);
    //cleaning up
    close(data->as);
}

void        handle_other(t_data *data)
{
    dprintf(data->as, "%s is an Invalid Command\n", data->u_input);
}