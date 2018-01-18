/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:39:16 by akinfemi          #+#    #+#             */
/*   Updated: 2017/11/16 14:57:39 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

void        handle_client(t_data *data)
{
    int     rd;
    char    buffer[1024];
    t_list  *tokens;
    t_token *tok;
    t_command * cmd;

    while((rd = read(data->as, buffer, 1023)) > 0)
    {
        buffer[rd] = '\0';
        data->u_input = ft_strtrim(buffer);
        printf("U_in: %s\n", data->u_input);
        tokens = ft_lexer(data->u_input);
        tok = (t_token *)tokens->content;
        printf("Tok: %s\n", tok->word);
        data->commands = ft_parser(tokens);
        cmd = (t_command *)data->commands->content;
        printf("CMD: %s\n", data->u_input);
        handle_command(data);
    }
}