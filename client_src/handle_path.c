/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:00:01 by akinfemi          #+#    #+#             */
/*   Updated: 2018/01/19 13:00:02 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

int         handle_path(t_data __attribute__((__unused__)) *data)
{
    char    path[PATH_MAX];

    getcwd(path, PATH_MAX);
    printf("%s\n", path);
    return (1);
}