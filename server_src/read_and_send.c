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

    write(sockfd, "rns\n",4);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        print_error(4);
    rd = get_next_line(fd, &line);
    while (rd > 0)
    {
        buffer = line;
        dprintf(sockfd, "line\n");
        // printf("%s \nRD: %d\n", line, rd);
        free(line);
        line = NULL;
        rd = get_next_line(fd, &line);
    }
}