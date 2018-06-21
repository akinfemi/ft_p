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

int         ft_contains(char *str, int c)
{
    if (!str || !*str)
        return (0);
    while(*str)
    {
        if (*str == c)
            return (1);
        str++;
    }
    return (0);
}

t_stack     *init_path(void)
{
    t_stack *p_stack;

    p_stack = stackInit();
    push(p_stack, ft_strdup("~"));
    return (p_stack);
}

void        pop_all(t_data *data)
{
    while(data->p_stack->size > 1)
        pop(data->p_stack);
}

int         set_path(t_data *data, char **args)
{
    char    *path;
    char    **path_args;
    int     i;

    i = 0;
    if (!args || !args[1])
    {
        pop_all(data);
        return (1);
    }
    path = args[1];
    if (ft_strcmp(path, "/") == 0)
        return (0);
    path_args = ft_strsplit(path, '/');
    while (path_args && path_args[i])
    {
        if (ft_strcmp(path_args[i], "..") == 0 && data->p_stack->size <= 1)
            return (0);
        if (ft_strcmp(path_args[i], "..") == 0 && data->p_stack->size > 1)
        {
            pop(data->p_stack);
        }
        else if (ft_strcmp(path, ".") != 0)
        {
            push(data->p_stack, path_args[i]);
        }
        i++;
    }
    return (1);
}

void        path_strjoin(char *path, char *str)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while(path[i])
        i++;
    while (str[j] != '\0' && i < PATH_MAX)
    {
        path[i] = str[j];
        j++;
        i++;
    }
    // free(str);
}

void        recurse(t_item *item, char *str, int len)
{
    if (item && item->next && len < PATH_MAX)
    {
        recurse(item->next, str, len);
        path_strjoin(str, item->word);
        path_strjoin(str, "/");
        len += ft_strlen(item->word) + 1;
    }
}

char        *get_path_pwd(t_data *data)
{
    t_item  *path;
    char    temp_path[PATH_MAX];
    char    *str;
    int     len;

    len = 0;
    path = data->p_stack->item;
    ft_bzero((char *)temp_path, PATH_MAX);
    path_strjoin(temp_path, "~");
    path_strjoin(temp_path, "/");
    str = (char *)malloc(sizeof(char) * PATH_MAX + 1);
    recurse(path, str, len);
    path_strjoin(temp_path, str);
    // free(str);
    return (ft_strdup(temp_path));
}

char        *get_path(t_data *data)
{
    t_item  *path;
    char    temp_path[PATH_MAX];
    char    *str;
    int     len;

    len = 0;
    path = data->p_stack->item;
    ft_bzero((char *)temp_path, PATH_MAX);
    path_strjoin(temp_path, data->home);
    path_strjoin(temp_path, "/");
    str = (char *)malloc(sizeof(char) * PATH_MAX + 1);
    recurse(path, str, len);
    path_strjoin(temp_path, str);
    // free(str);
    return (ft_strdup(temp_path));
}


int         handle_path(t_data *data)
{
    char    *path;

    path = get_path_pwd(data);
    dprintf(data->cmd_as,"pwd:SUCCESS\n%s\n", path);
    free(path);
    return (1);
}