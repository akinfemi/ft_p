/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 10:48:50 by akinfemi          #+#    #+#             */
/*   Updated: 2017/12/27 10:48:53 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void            *ft_realloc(void *alloc, size_t src_size, size_t size)
{
    void        *ptr;

    if (!alloc)
        return (ft_memalloc(size));
    if (0 == size)
    {
        free(alloc);
        return (NULL);
    }
    ptr = alloc;
    alloc = ft_memalloc(size);
    if (!alloc)
        return (ptr);
    ft_memmove(alloc, ptr, src_size);
    free(ptr);
    return (alloc);
}