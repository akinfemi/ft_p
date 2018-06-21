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
# include <limits.h>
# include <dirent.h>
# define BUFFER_SIZE 4068
# define EXIST_ERROR 0x03
# define OPEN_ERROR 0x04

typedef struct      s_data
{
    char            home[PATH_MAX];
    int             home_len;
    char            *u_input;
    int             cmd_as;
    int             data_socket;
    int             data_as;
    char            *ip;
    t_stack         *p_stack;
    t_list          *commands;
}                   t_data;

void        usage(char *exec_name);
void		print_error(int error);
void        handle_client(t_data *data);
void        handle_command(t_data *data);
void        handle_response(int socket_fd);
void        read_welcome(int socket_fd);
int         handle_ls(t_data *data);
int         handle_get(t_data *data);
int         handle_put(t_data *data);
int         handle_quit(t_data *data);
int         handle_cd(t_data *data);
int         handle_path(t_data *data);
int         handle_other(t_data *data);
void        read_and_send(t_data *data);
int         dispatch(t_data *data);
t_stack     *init_path(void);
char        *get_path(t_data *data);
void        path_strjoin(char *path, char *str);
int         set_path(t_data *data, char **args);
char        *get_path_pwd(t_data *data);
int         client_handles(char *buffer, t_data *data);
t_data      *init_cl_data(int accepted_socket, char *ip_addr);

#endif