/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 23:13:41 by aakin-al          #+#    #+#             */
/*   Updated: 2017/06/24 09:21:55 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*handle_conv(va_list ap, char arg, t_format *params)
{
	char		*str;
	intmax_t	val;

	if (arg == 'd' || arg == 'i' || arg == 'D')
	{
		if (arg == 'D')
			params->lmod = 'l';
		val = ft_di_len(ap, params);
		params->minus = (val < 0) ? 1 : 0;
		val *= (params->minus) ? -1 : 1;
		str = ft_imaxtoa(val);
		return (str);
	}
	else if (ft_is_set(arg))
		return (handle_conv2(ap, arg, params));
	return (0);
}

int			ft_is_set(char arg)
{
	char	*set;

	set = "sScC%uUxXpoO";
	while (*set)
	{
		if (*set == arg)
			return (1);
		set++;
	}
	return (0);
}

char		*handle_conv2(va_list ap, char arg, t_format *params)
{
	if (arg == 's' || arg == 'S')
		return (va_arg(ap, char *));
	else if (arg == 'c' || arg == 'C')
		return (ft_padstr(va_arg(ap, int), 1));
	else if (arg == '%')
		return (ft_padstr(arg, 1));
	else if (arg == 'o')
		return (ft_itoa_base(ft_oux_len(ap, params), 8));
	else if (arg == 'u')
		return (ft_itoa_base(ft_oux_len(ap, params), 10));
	else if (arg == 'U')
		return (ft_itoa_upper_base(ft_upper_u_len(ap), 10));
	else if (arg == 'x')
		return (ft_itoa_base(ft_oux_len(ap, params), 16));
	else if (arg == 'X')
		return (ft_itoa_upper_base(ft_oux_len(ap, params), 16));
	else if (arg == 'p')
		return (ft_handle_p(ap, params));
	else if (arg == 'O')
	{
		params->lmod = 'l';
		return (ft_itoa_base(ft_oux_len(ap, params), 8));
	}
	return (0);
}

intmax_t	ft_di_len(va_list ap, t_format *params)
{
	if (params->lmod == 'L')
		return (va_arg(ap, long long));
	else if (params->lmod == 'h')
		return ((short)va_arg(ap, int));
	else if (params->lmod == 'l')
		return (va_arg(ap, long));
	else if (params->lmod == 'z')
		return (va_arg(ap, size_t));
	else if (params->lmod == 'j')
		return (va_arg(ap, intmax_t));
	else if (params->lmod == 'H')
		return ((char)va_arg(ap, unsigned int));
	else
		return (va_arg(ap, int));
}

uintmax_t	ft_oux_len(va_list ap, t_format *params)
{
	if (params->lmod == 'j')
		return (va_arg(ap, uintmax_t));
	else if (params->lmod == 'z')
		return (va_arg(ap, size_t));
	else if (params->lmod == 'L')
		return (va_arg(ap, unsigned long long));
	else if (params->lmod == 'l')
		return (va_arg(ap, unsigned long));
	else if (params->lmod == 'h')
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (params->lmod == 'H')
		return ((unsigned char)va_arg(ap, int));
	else
		return (va_arg(ap, unsigned int));
}
