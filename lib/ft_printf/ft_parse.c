/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 10:15:35 by aakin-al          #+#    #+#             */
/*   Updated: 2017/06/23 03:37:45 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_output(t_output **output)
{
	t_output	*out;

	out = *output;
	out->res = ft_strnew(0);
	out->len = 0;
}

void		clean_output(t_output **output)
{
	t_output	*out;

	out = *output;
	if (out->res)
		ft_strdel(&out->res);
}

void		ft_clean(t_output **output)
{
	t_output	*out;

	out = *output;
	free(out->res);
	free(out);
	output = NULL;
}

void		init_params(t_format **p)
{
	t_format	*params;

	params = *p;
	params->minus = 0;
	params->flag_minus = 0;
	params->plus = 0;
	params->zero = 0;
	params->space = 0;
	params->hash = 0;
	params->min_width = 0;
	params->precision = 0;
	params->period = 0;
	params->conv = '\0';
	params->lmod = '\0';
}

void		ft_parse(va_list ap, const char **fmt, t_output **output)
{
	t_format	*params;
	const char	*tmp;

	params = (t_format *)malloc(sizeof(t_format));
	init_params(&params);
	*fmt = *fmt + 1;
	params->conv = (**fmt == '%') ? '%' : '\0';
	*fmt = (params->conv == '%') ? *fmt + 1 : *fmt;
	while (*fmt && **fmt && **fmt != '%' && params->conv != '%')
	{
		tmp = *fmt;
		set_flags(&params, fmt);
		set_min_width(&params, fmt, ap);
		set_precision(&params, fmt, ap);
		set_args(&params, fmt);
		tmp++;
		if (*tmp == '\0' || --tmp - *fmt == 0 || params->conv != '\0')
			break ;
	}
	if (!*fmt)
		return ;
	if (ft_is_valid(params->conv) == 0)
		return ;
	ft_build(ap, params, output);
	free(params);
}
