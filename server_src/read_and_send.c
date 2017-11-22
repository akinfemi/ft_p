/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_send.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:39:16 by akinfemi          #+#    #+#             */
/*   Updated: 2017/11/16 14:57:39 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

void        read_and_send(int sockfd, char *filename)
{
    int     fd;
    int     rd;
    char    *line;
    void    *buffer;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        print_error(4);
    while ((rd = get_next_line(fd, &line)) > 0)
    {
        buffer = line;
        dprintf(sockfd, "%s", line);
        free(line);
        line = NULL;
    }
}