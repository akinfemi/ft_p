/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:22:26 by akinfemi          #+#    #+#             */
/*   Updated: 2017/11/16 14:55:02 by akinfemi         ###   ########.fr       */
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
		printf("Bind error\n");
		exit(-1);
	}
	else if (error == 3)
	{
		printf("Connection accept error\n");
		exit(-1);
	}
	else if (error == 4)
	{
		printf("Error opening file\n");
		exit(-1);
	}
}
