/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:22:26 by akinfemi          #+#    #+#             */
/*   Updated: 2017/11/16 19:33:10 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

void		print_error(int error)
{
	if (error == 1)
	{
		printf("No protocol number in the /etc/protocol file\n");
		exit(-1);
	}
	else if (error == 2)
	{
		printf("Connection error.\n");
		exit(2);
	}
	else if (error == 3)
	{
		printf("Socket failure.\n");
		exit(2);
	}
}
