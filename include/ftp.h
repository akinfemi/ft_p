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
# define WORD 1
# define CHAIN 2
# define INIT_SIZE 10

typedef struct      s_token
{
    char            *word;
    int             type;
}                   t_token;

typedef struct      s_command
{
    char            *bin;
    char            **flags;
    char            **args;
}                   t_command;

typedef struct      s_data
{
    char            home[MAXPATHLEN];
    int             home_len;
    char            path[MAXPATHLEN];
    char            *u_input;
    int             as;
    t_list          *commands;
}                   t_data;

typedef struct  s_exec
{
    char        *bin;
    char        **args;
    int         chain;
}               t_exec;

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

/*<-- Lexer and Parser -->*/
t_list      *ft_lexer(char *input);
t_list      *ft_parser(t_list *tokens);
t_list      *ft_tokenize(char **words);
char        **sh_strsplit(char *words);

#endif