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

t_data			*init_data(int accepted_socket)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->cmd_as = accepted_socket;
	getcwd(data->home, PATH_MAX);
	data->home_len = ft_strlen(data->home);
	data->home[data->home_len] = '\0';
	data->p_stack = init_path();
	data->commands = NULL;
	data->u_input = NULL;
	return (data);
}

int				create_server(int port)
{
	int					sockt;
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

int				main(int ac, char **av)
{
	int					port;
	int					socket;
	int					cs;
	unsigned int 		addr_len;
	struct sockaddr_in	addr;
	int					pid;
	t_data				*data;

	if (ac != 2)
		usage(av[0]);
	port = ft_atoi(av[1]);
	socket = create_server(port);
	while (1)
	{
		cs = accept(socket, (struct sockaddr *)&addr, &addr_len);
		if (cs == -1)
			print_error(3);
		if ((pid = fork()) == -1)
		{
			close(cs);
			continue;
		}
		if (pid == 0) //on child processes only
		{
			printf("Client connected.\n"); //on server
			write(cs, "Welcome to ft_p server", 22); // to client
			data = init_data(cs);
			handle_client(data);
		}
	}
	close(cs);
	close(socket);
	return(0);
}