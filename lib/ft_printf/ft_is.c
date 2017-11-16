/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 23:24:03 by aakin-al          #+#    #+#             */
/*   Updated: 2017/06/20 13:04:32 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_is_conv(char *str)
{
	char	*conv;

	conv = "sSpdDioOuUxXcC%";
	while (*conv)
	{
		if (*str == *conv)
			return (1);
		conv++;
	}
	return (0);
}

int			ft_is_valid(char c)
{
	char	*conv;

	conv = "sSpdDioOuUxXcC%";
	while (*conv)
	{
		if (c == *conv)
			return (1);
		conv++;
	}
	return (0);
}

int			ft_is_slmod(const char *str)
{
	char	*slmod[3];
	int		i;

	slmod[0] = "hh";
	slmod[1] = "ll";
	slmod[2] = "\0";
	i = 0;
	while (i < 2)
	{
		if (ft_strncmp(slmod[i], str, 2) == 0)
			return (1);
		i++;
	}
	return (0);
}

int			ft_is_lmod(const char ch, t_format **p)
{
	char		*lmod;
	t_format	*params;
	int			i;

	params = *p;
	lmod = "hljz";
	i = -1;
	while (++i < 4)
	{
		if (ch == lmod[i])
		{
			if (params->lmod == '\0')
				params->lmod = ch;
			else if (ch == 'l' && (params->lmod == 'h' || params->lmod == 'H'))
				params->lmod = ch;
			else if (ch == 'z' && (ft_tolower(params->lmod) == 'l'
						|| ft_tolower(params->lmod) == 'h'))
				params->lmod = ch;
			else if (ch == 'j')
				params->lmod = ch;
			return (1);
		}
	}
	return (0);
}
