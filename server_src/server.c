/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:39:16 by akinfemi          #+#    #+#             */
/*   Updated: 2017/11/16 14:57:39 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

int		create_server(int port)
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
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(sockt, (const struct sockaddr *)&addr, sizeof(addr)) == -1)
		print_error(2);
	listen(sockt, 42);
	return(sockt);
}

int		main(int ac, char **av)
{
	int			port;
	int			socket;
	int			cs;
	unsigned int 		addr_len;
	struct sockaddr_in	addr;
	char			buffer[1024];
	int			rd;

	if (ac != 2)
		usage(av[0]);
	port = ft_atoi(av[1]);
	socket = create_server(port);
	cs = accept(socket, (struct sockaddr *)&addr, &addr_len);
	while ((rd = read(cs, buffer, 1023)) > 0)
	{
		buffer[rd] = '\0';
		ft_printf("%s\n",buffer);
	}
	close(cs);
	close(socket);
	return(0);
}
