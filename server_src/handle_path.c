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
    // int     len;
    // char    *temp;
    // char    *t_path;

    i = 0;
    if (!args || !args[1])
    {
        pop_all(data);
        return (1);
    }
    path = args[1];
    if (ft_strcmp(path, "/") == 0) //prevent root access
        return (0);
    path_args = ft_strsplit(path, '/');
    while (path_args && path_args[i])
    {
        if (ft_strcmp(path_args[i], "..") == 0 && data->p_stack->size <= 1)
            return (0);
        if (ft_strcmp(path_args[i], "..") == 0 && data->p_stack->size > 1)
        {
            pop(data->p_stack);
            data->p_stack->temp++;
        }
        else
        {
            push(data->p_stack, path_args[i]);
            data->p_stack->temp++;
        }
        i++;
    }
    return (1);
    // while (path && *path)
    // {
    //     //if only one dir
    //     temp = ft_strchr(path, '/');
    //     if (temp)
    //         t_path = ft_strsub(path, temp - path, ft_strlen(temp));
    //     if (!temp && ft_strncmp(path, "..", 2) != 0)
    //     {
    //         push(data->p_stack, path);
    //         printf("Push: %s\n", path);
    //         path = "\0";
    //         break;
    //     }
    //     if (ft_strncmp(path, "..", 2) == 0 && data->p_stack->size > 1)
    //     {
    //         printf("popped\n");
    //         pop(data->p_stack);
    //         if (path[2] == '/')
    //         {
    //             printf("Path before: {%s}\n", path);
    //             len = ft_strlen(path) - 3;
    //             ft_memmove(path, path + 3, len);
    //             path[len] = '\0';
    //             printf("Path after: {%s}\n", path);
    //         }
    //         else if (path[2] == '\0')
    //             ft_bzero(path, 3)
    //     }
    //     else if (ft_strncmp(path, "..", 2) == 0 && data->p_stack->size <= 1)
    //         break;
    // }
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

char        *recurse(t_item *item)
{
    static char *path = NULL;

    if (!path)
        path = (char *)malloc(sizeof(char) * PATH_MAX + 1);
    if (!item || !item->next)
        return (path);
    recurse(item->next);
    path_strjoin(path, item->word);
    path_strjoin(path, "/");
    return (path);
}

char        *get_path(t_data *data)
{
    t_item  *path;
    char    temp_path[PATH_MAX];
    char    *temp;

    path = data->p_stack->item;
    ft_bzero((char *)temp_path, PATH_MAX);
    path_strjoin(temp_path, data->home);
    path_strjoin(temp_path, "/");
    temp = recurse(path);
    printf("recurse res: %s\n", temp);
    printf("temp path before: %s\n", temp_path);
    path_strjoin(temp_path, temp);
    printf("temp path after: %s\n", temp_path);
    ft_bzero(temp, PATH_MAX);
    // free(temp);
    return (ft_strdup(temp_path));
}

int         handle_path(t_data *data)
{
    char    *path;

    path = get_path(data);
    dprintf(data->as,"%s\n", path);
    free(path);
    return (1);
}