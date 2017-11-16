/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:02:34 by aakin-al          #+#    #+#             */
/*   Updated: 2017/09/01 10:32:40 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_repnull(t_output **output)
{
	t_output	*out;
	char		*str;

	out = *output;
	if (!out)
		return ;
	str = out->res;
	while (str && *str)
	{
		if (*str == 127)
			*str = 0;
		str++;
	}
}

int			ft_print(const char *fmt, va_list ap)
{
	const char	*temp;
	t_output	*output;
	int			out_len;
	int			n;

	out_len = 0;
	output = (t_output *)malloc(sizeof(t_output));
	init_output(&output);
	while (fmt && *fmt)
	{
		clean_output(&output);
		temp = ft_strchr(fmt, '%');
		if (!temp || temp - fmt > 0)
			ft_add(ft_strndup(fmt, temp - fmt), &output, 4);
		fmt = temp;
		if (fmt)
			ft_parse(ap, &fmt, &output);
		out_len += ft_strlen(output->res);
		n = ft_strlen(output->res);
		ft_repnull(&output);
		write(1, output->res, n);
	}
	ft_clean(&output);
	return (out_len);
}

int			ft_printf(const char *fmt, ...)
{
	int		res;
	va_list	ap;

	va_start(ap, fmt);
	res = ft_print(fmt, ap);
	va_end(ap);
	return (res);
}
