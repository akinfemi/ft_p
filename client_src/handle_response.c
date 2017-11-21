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
    int     rd;
    char    buffer[1024];

    rd = read(socket_fd, buffer, 1023);
    buffer[rd] = '\0';
    printf("server says: %s", buffer);
    // while(rd > 0){
    //     buffer[rd] = '\0';
    //     printf("server says: %s", buffer);
    //     printf("RD:%d\n", rd);
    //     rd = read(socket_fd, buffer, 1023);
    //     printf("RD:%d\n", rd);
    // }
}