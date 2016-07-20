/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 21:24:52 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/07 05:52:49 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "../libft/includes/libft.h"

typedef struct	s_printf
{
	int			ret;
	int			ret_wchar;
	int			space_number;
	int			valid;
	int			negatif;
	int			zero;
	int			d;
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
void			percent_p(va_list pa, t_printf *print);
void			percent_O(va_list pa, t_printf *print);
void			percent_C(va_list pa, t_printf *print);
void			percent_S(va_list pa, t_printf *print);
void			percent_p(va_list pa, t_printf *print);
void			init_struct(t_printf *printf);
const char		*check_valid_specifier(const char *format, t_printf *print);
const char		*countSpace(const char *format, t_printf *print);
const char		*check_neg_sign(t_printf *print, const char *format);
void			write_space_hex(int space, t_printf *print);
void			write_space_percent_s(int space, t_printf *print);

#endif
