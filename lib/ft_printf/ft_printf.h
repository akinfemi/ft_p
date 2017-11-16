/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:04:43 by aakin-al          #+#    #+#             */
/*   Updated: 2017/09/01 10:36:31 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"
# include <stdint.h>
# include <limits.h>

typedef struct	s_output
{
	char		*res;
	int			len;
}				t_output;
typedef struct	s_format
{
	int			minus;
	int			plus;
	int			zero;
	int			hash;
	int			space;
	int			min_width;
	int			period;
	int			precision;
	char		conv;
	char		lmod;
	int			flag_minus;
}				t_format;
int				ft_printf(const char *fmt, ...);
void			ft_add(char *str, t_output **output, int b);
void			ft_parse(va_list ap, const char **fmt, t_output **output);
void			ft_build(va_list ap, t_format *p, t_output **output);
void			set_flags(t_format **p, const char **fmt);
void			set_min_width(t_format **p, const char **fmt, va_list ap);
void			set_precision(t_format **p, const char **fmt, va_list ap);
void			set_args(t_format **p, const char **fmt);
int				ft_is_conv(char *str);
int				ft_is_valid(char c);
void			init_output(t_output **output);
void			clean_output(t_output **output);
char			*handle_conv(va_list ap, char arg, t_format *params);
char			*ft_padstr(char ch, int len);
int				ft_is_slmod(const char *str);
int				ft_is_lmod(const char ch, t_format **params);
intmax_t		ft_di_len(va_list ap, t_format *params);
char			*ft_ctostr(char ch);
uintmax_t		ft_oux_len(va_list ap, t_format *params);
int				ft_is_dioux(char c);
int				ft_is_diox(char c);
int				ft_is_di(char c);
uintmax_t		ft_upper_u_len(va_list ap);
void			handle_hash(t_format **p, t_output **output);
void			handle_plus(t_format **params, t_output **output);
void			handle_space(t_format **params, t_output **output);
void			handle_padding(t_format **p, t_output **o, char *r, int l);
void			handle_minus(t_format **params, t_output **output);
void			handle_precision(t_format **params, t_output **o, int l);
void			handle_res(t_format **params, t_output **o, char *r, int l);
void			handle_alignment(t_format **params, t_output **output);
int				set_len(t_format **params, char *res, int len);
char			*ft_handle_p(va_list ap, t_format *params);
void			ft_clean(t_output **output);
void			add_postfix (t_format **p, t_output **o, char *r, char ch);
int				ft_is_set(char arg);
char			*handle_conv2(va_list ap, char arg, t_format *params);
void			add_prefix(t_format **p, t_output **o, char *r, char ch);
char			set_ch(t_format **params);
int				ft_isox(char c);
int				ft_is_flag(char arg);
#endif
