/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 09:05:53 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/08 16:12:16 by rabougue         ###   ########.fr       */
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
	int			neg_sign;
	int			negatif_x;
	int			zero;
	int			d;
	int			ok;
	int			sharp;
	int			plus;
	int			space;
	int			point;
	int			precision_zero;
	int			precision_space;
	int			i;
}				t_printf;

const char		*percent_percent(const char *format, t_printf *printf);
const char		*percent_percent_neg(const char *format, t_printf *printf);
const char		*if_percent(const char *format, t_printf *printf);
const char		*percent_c(va_list pa, t_printf *print, const char *format);
const char		*percent_x(va_list pa, t_printf *print, const char *format);
const char		*percent_l(va_list pa, t_printf *print, const char *format);
const char		*percent_j(va_list pa, t_printf *print, const char *format);
const char		*percent_h(va_list pa, t_printf *print, const char *format);
const char		*percent_z(va_list pa, t_printf *print, const char *format);
const char		*percent_d(va_list pa, t_printf *print, const char *format);
const char		*percent_d_up(va_list pa, t_printf *print, const char *f);
const char		*percent_o(va_list pa, t_printf *print, const char *format);
const char		*check_valid_specifier(const char *format, t_printf *print);
const char		*count_espace(const char *format, t_printf *print);
const char		*check_neg_sign(t_printf *print, const char *format);
const char		*check_space(const char *format, t_printf *print);
const char		*precision(const char *format, int d, t_printf *print);
const char		*take_precision(const char *format, t_printf *print);
void			write_space_int(int space, t_printf *print);
void			write_space_wchar(t_printf *print);
void			write_space_char(char *p, t_printf *print);
void			write_space_int_other(t_printf *print, const char *format);
void			percent_u_up(va_list pa, t_printf *print);
void			percent_o_up(va_list pa, t_printf *print);
void			percent_c_up(va_list pa, t_printf *print);
void			percent_s_up(va_list pa, t_printf *print);
void			percent_p(va_list pa, t_printf *print, const char *format);
void			init_struct(t_printf *printf);
void			write_space_hex(long space, t_printf *print);
void			write_space_percent_s(int space, t_printf *print);
void			put_space_or_zero(t_printf *print, int d);
void			put_space_or_zero_u(t_printf *print, unsigned int d);
void			put_space_or_zero_o(t_printf *print, int o);
void			put_space_or_zero_x(t_printf *print, int x);
void			put_space_or_zero_s(t_printf *print, char *s);
void			percent_s(va_list pa, t_printf *print);
void			struct_is_zero(t_printf *print, const char *format);
int				space_zero(t_printf *print, const char *format, int d);
int				ft_printf(const char *format, ...);
int				count_space(const char *format);
int				is_precision_ok(const char *format, t_printf *print);
/*
** percent_l.c
*/
const char		*percent_l(va_list pa, t_printf *print, const char *format);
/*
** percent_l_2.c
*/
void			percent_l_5(va_list pa, t_printf *print, const char *f);
void			percent_l_6(va_list pa, t_printf *print, const char *f);
/*
** write_space_or_zero.c
*/
void			loop_zero(t_printf *print);
void			loop_space(t_printf *print);
void			while_nb_zero(int nb_zero, t_printf *print);
void			while_space_number(t_printf *print);
void			while_space(t_printf *print);
/*
** write_space_or_zero_2.c
*/
void			loop_space_no_ret(t_printf *print);
/*
** space_or_zero.c
*/
int				space_zero(t_printf *print, const char *format, int d);
void			put_space_or_zero(t_printf *print, int d);
/*
** check_struct.c
*/
void			decr_space_number(t_printf *print);
void			decr_precision_zero(t_printf *print, int z);
void			struct_is_zero(t_printf *print, const char *format);
/*
** percent_d.c
*/
const char		*percent_d(va_list pa, t_printf *print, const char *format);
/*
** percent_d_2.c
*/
const char		*percent_d_5(const char *f, t_printf *print, int d);
/*
** percent_d.c
*/
const char		*percent_x(va_list pa, t_printf *print, const char *format);
/*
** width_2.c
*/
void			write_space_hex(long space, t_printf *print);

#endif
