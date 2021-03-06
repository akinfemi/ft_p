/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:52:46 by akinfemi          #+#    #+#             */
/*   Updated: 2017/11/16 11:54:06 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

void		usage(char *exec_name)
{
	ft_printf("Usage: %s <ip_address> <port_number>\n", exec_name);
	exit(-1);
}
