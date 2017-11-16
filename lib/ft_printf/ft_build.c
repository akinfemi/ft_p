/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 09:22:25 by aakin-al          #+#    #+#             */
/*   Updated: 2017/09/01 10:37:06 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_build(va_list ap, t_format *p, t_output **output)
{
	char		*res;
	int			len;

	res = handle_conv(ap, p->conv, p);
	if (p->conv == 's' && p->precision == 0 && p->period == 1)
		res = "";
	len = ft_strlen(res);
	handle_space(&p, output);
	handle_padding(&p, output, res, len);
	handle_precision(&p, output, len);
	handle_res(&p, output, res, len);
	handle_alignment(&p, output);
	if (!(p->conv == 's' || p->conv == 'S'))
		free(res);
}

void		ft_add(char *str, t_output **output, int signal)
{
	t_output	*out;
	char		*temp;

	out = *output;
	if (signal == 3 || signal == 1)
		out->len += ft_strlen(str);
	else if (signal == 2)
	{
		*str = 127;
		out->len += 1;
	}
	temp = out->res;
	out->res = ft_strjoin(out->res, str);
	if (ft_strlen(temp))
		free(temp);
	if (signal == 3 || signal == 4)
		free(str);
}
