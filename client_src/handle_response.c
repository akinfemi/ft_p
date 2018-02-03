/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_response.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:39:16 by akinfemi          #+#    #+#             */
/*   Updated: 2017/11/16 19:39:01 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

void        handle_response(int socket_fd)
{
    size_t      rd;
    char        buffer[4096];

    while ((rd = recv(socket_fd, buffer, 4095, 0)) > 0)
    {
        buffer[rd] = '\0';
        printf("%s", buffer);
        if (rd < 4095)
            break;
    }
}