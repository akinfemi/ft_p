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

void		usage(char *exec_name);
void		print_error(int error);
void        handle_client(int socket_fd);
void        handle_command(int socket, char *buffer);
void        handle_response(int socket_fd);
void        read_welcome(int socket_fd);
void        handle_ls(int socket_fd, char *flags);
void        handle_get(int socket_fd, char *filename);
void        handle_put(int socket_fd, char *filepath, char *destination);
void        handle_quit(int socket_fd);
void        handle_cd(int socket_fd, char *dest);
void        handle_path(int socket_fd);
void        handle_other(int socket_fd, char *buffer);
void        read_and_send(int sockfd, char *filename);

#endif