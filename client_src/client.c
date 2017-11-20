/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:39:16 by akinfemi          #+#    #+#             */
/*   Updated: 2017/11/16 19:39:01 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

int		create_client(char *ip_addr, int port)
{
	int			sockt;
	struct protoent		*protocol;
	struct sockaddr_in	addr;

	protocol = getprotobyname("tcp");
	if (!protocol)
		print_error(1);
	sockt = socket(PF_INET, SOCK_STREAM, protocol->p_proto);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ip_addr);
	if(connect(sockt, (const struct sockaddr *)&addr, sizeof(addr)) == -1)
		print_error(2);
	listen(sockt, 42);
	return(sockt);
}

int		main(int ac, char **av)
{
	int			port;
	int			sockt;
	int			rd;
	char		buffer[1024];

	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	sockt = create_client(av[1], port);
	if (sockt == -1)
		print_error(3);
	read_welcome(sockt);
	write(1, "$> ", 3);
	while ((rd = read(0, buffer, 1023)) > 0)
	{
		write(1, "$> ", 3);
		buffer[rd] = '\0';
		dprintf(sockt, "%s",buffer); //send to sockt
		handle_response(sockt);
	}
	close(sockt);
	return(0);
}