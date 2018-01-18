/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:36:08 by akinfemi          #+#    #+#             */
/*   Updated: 2017/11/16 13:51:37 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H
# include <unistd.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdio.h>
# include <fcntl.h>
# include "../lib/includes/lib.h"
# define MAXPATHLEN 2048

typedef struct      s_command
{
    char            *bin;
    char            **flags;
    char            **args;
}                   t_command;

typedef struct      s_data
{
    int             socket_fd;
    char            home[MAXPATHLEN];
    int             home_len;
    char            path[MAXPATHLEN];
    char            *u_input;
    int             as;
    t_command       *command;
}                   t_data;

void        usage(char *exec_name);
void		print_error(int error);
void        handle_client(t_data *data);
void        handle_command(t_data *data);
void        handle_response(int socket_fd);
void        read_welcome(int socket_fd);
void        handle_ls(t_data *data);
void        handle_get(t_data *data);
void        handle_put(t_data *data);
void        handle_quit(t_data *data);
void        handle_cd(t_data *data);
void        handle_path(t_data *data);
void        handle_other(t_data *data);
void        read_and_send(t_data *data);

/*<-- Lexer and Parser -->*/

#endif