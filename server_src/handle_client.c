/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:39:16 by akinfemi          #+#    #+#             */
/*   Updated: 2017/11/16 14:57:39 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

void        handle_client(t_data *data)
{
    int     rd;
    char    buffer[1024];

    while((rd = read(data->as, buffer, 1023)) > 0)
    {
        buffer[rd] = '\0';
        data->u_input = ft_strtrim(buffer);
        handle_command(data);
    }
}