
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 21:24:52 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/03 06:34:51 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
//# include <limits.h>
# include "../libft/includes/libft.h"

typedef struct	s_printf
{
	int			ret;
	int			ret_wchar;
	int			space_number;
	int			valid;
	int			negatif;
	int			negatif_x;
	int			zero;
	int			d;
	int			sharp;
	int			plus;
	int			space;
	int			point;
	int			precision_zero;
	int			precision_space;
}				t_printf;
/*
** percent_percent.c
*/
const char		*percent_percent(const char *format, t_printf *printf);
const char		*percent_percent_neg(const char *format, t_printf *printf);
const char		*if_percent(const char *format, t_printf *printf);

int				ft_printf(const char *format, ...);
int				count_space(const char *format);
void			percent_s(va_list pa, t_printf *print);

void			write_space_int(int space, t_printf *print);
void			write_space_wchar(t_printf *print);
void			write_space_char(char *p, t_printf *print);
void			write_space_int_other(t_printf *print, const char *format);
const char		*percent_c(va_list pa, t_printf *print, const char *format);
const char		*percent_x(va_list pa, t_printf *print, const char *format);
const char		*percent_l(va_list pa, t_printf *print, const char *format);
const char		*percent_j(va_list pa, t_printf *print, const char *format);
const char		*percent_h(va_list pa, t_printf *print, const char *format);
const char		*percent_z(va_list pa, t_printf *print, const char *format);
const char		*percent_d(va_list pa, t_printf *print, const char *format);
const char		*percent_D(va_list pa, t_printf *print, const char *format);
const char		*percent_o(va_list pa, t_printf *print, const char *format);
void			percent_U(va_list pa, t_printf *print);
void			percent_O(va_list pa, t_printf *print);
void			percent_C(va_list pa, t_printf *print);
void			percent_S(va_list pa, t_printf *print);
void			percent_p(va_list pa, t_printf *print, const char *format);
void			init_struct(t_printf *printf);
const char		*check_valid_specifier(const char *format, t_printf *print);
const char		*countSpace(const char *format, t_printf *print);
const char		*check_neg_sign(t_printf *print, const char *format);
void			write_space_hex(long space, t_printf *print);
void			write_space_percent_s(int space, t_printf *print);
const char		*check_space(const char *format, t_printf *print);
const char		*precision(const char *format, int d, t_printf *print);
int				space_zero(t_printf *print, const char *format, int d);
void			put_space_or_zero(t_printf *print, int d);
const char		*take_precision(const char *format, t_printf *print);
int				is_precision_ok(const char *format, t_printf *print);
void			put_space_or_zero_u(t_printf *print, unsigned int d);
void			put_space_or_zero_o(t_printf *print, int o);
void			put_space_or_zero_x(t_printf *print, int x);
void			put_space_or_zero_s(t_printf *print, char *s);

#endif
