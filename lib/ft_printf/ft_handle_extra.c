/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 23:06:45 by aakin-al          #+#    #+#             */
/*   Updated: 2017/06/24 09:18:06 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_len(t_format **params, char *res, int n)
{
	t_format	*p;
	int			len;

	len = n;
	p = *params;
	len = (p->precision > 0) ? p->precision : len;
	len = (p->conv == 's' && p->precision > n) ? n : len;
	len = (ft_is_dioux(p->conv) && p->precision < n) ? n : len;
	len += (p->hash && (p->conv == 'x' || p->conv == 'X')) ? 2 : 0;
	len = (p->conv == 'c' && ft_strlen(res) == 0) ? 1 : len;
	return (len);
}

int		ft_is_scperc(char ch)
{
	return (ch == 's' || ch == 'c' || ch == '%');
}

char	set_ch(t_format **params)
{
	char		ch;
	t_format	*p;

	p = *params;
	ch = (p->zero && p->period == 0) ? '0' : ' ';
	if (p->zero && p->period && (ft_is_scperc(p->conv)))
		ch = '0';
	return (ch);
}

char	*ft_handle_p(va_list ap, t_format *p)
{
	char	*str;
	char	*temp;
	char	*s;
	int		n;

	temp = ft_strnew(0);
	s = ft_itoa_base(va_arg(ap, intmax_t), 16);
	if (ft_strcmp(s, "0") == 0 && p->precision == 0 && p->period == 1)
	{
		ft_strdel(&s);
		s = ft_strnew(0);
	}
	n = ft_strlen(s);
	if (p->precision > n)
		temp = ft_padstr('0', p->precision - n);
	str = ft_strjoin(temp, s);
	ft_strdel(&s);
	s = str;
	str = ft_strjoin("0x", str);
	ft_strdel(&temp);
	ft_strdel(&s);
	return (str);
}

void	add_prefix(t_format **params, t_output **output, char *res, char ch)
{
	t_format	*p;

	p = *params;
	if (p->hash && ft_tolower(p->conv) == 'x' && p->zero && *res != '0')
		handle_hash(&p, output);
	if (p->minus && ch == '0')
		handle_minus(params, output);
	if (ch == '0' && p->plus)
		handle_plus(params, output);
}
