/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 23:02:23 by aakin-al          #+#    #+#             */
/*   Updated: 2017/11/02 23:06:51 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_sqrt(size_t num)
{
	size_t	i;

	i = 1;
	while (i * i <= num)
		i++;
	return ((int)i - 1);
}
