/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 02:49:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/10 02:51:30 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*ft_printf_1(const char *format, t_printf *print)
{
	if (ft_isdigit(*format) == TRUE && *format != '0')
		format = take_precision(format, print);
	format = check_neg_sign(print, format);
	format = check_flag(format, print);
	format = check_flag(format, print);
	format = check_neg_sign(print, format);
	check_valid_specifier(format, print);
	if (print->precision_space > 0 && print->precision_zero <= 0)
		print->d = 1;
	if (*format == '%')
		format = if_percent(format, print);
	return (format);
}

const char	*ft_printf_2(const char *format, t_printf *print)
{
	if (ft_isdigit(*format) == TRUE)
		format = count_espace(format, print);
	if (*format == '.' || *format == '+')
	{
		if (*format == '+')
			print->plus = 1;
		else if (*format == '.')
			print->point = 1;
		++format;
	}
	if (ft_isdigit(*format) == TRUE)
	{
		if (*--format == '.' || *format == '+')
		{
			++format;
			print->precision_zero = ft_atoi(format);
		}
		++format;
	}
	return (format);
}

const char	*ft_printf_3(const char *format, t_printf *print, va_list pa)
{
	if (*format == 'l')
		format = percent_l(pa, print, format);
	else if (*format == 'h')
		format = percent_h(pa, print, format);
	else if (*format == 'j')
		format = percent_j(pa, print, format);
	else if (*format == 'z')
		format = percent_z(pa, print, format);
	else if (*format == 's')
		percent_s(pa, print);
	else if (*format == 'd' || *format == 'i')
		percent_d(pa, print, format);
	else if (*format == 'D' || *format == 'u')
		percent_d_up(pa, print, format);
	return (format);
}

const char	*ft_printf_4(const char *format, t_printf *print, va_list pa)
{
	if (*format == 'U')
		percent_u_up(pa, print);
	else if (*format == 'p')
		percent_p(pa, print, format);
	else if (*format == 'o')
		percent_o(pa, print, format);
	else if (*format == 'O')
		percent_o_up(pa, print);
	else if (*format == 'c')
		format = percent_c(pa, print, format);
	else if (*format == 'x' || *format == 'X')
		format = percent_x(pa, print, format);
	else if (*format == 'C')
		percent_c_up(pa, print);
	else if (*format == 'S')
		percent_s_up(pa, print);
	return (format);
}

const char	*ft_printf_5(const char *f, t_printf *print, va_list pa)
{
	f = ft_printf_1(f, print);
	if (*f != '%')
	{
		f = ft_printf_2(f, print);
		if (print->negatif == 1 && *f != 'x')
			print->zero = 0;
		while (print->precision_zero > 0 && ft_isdigit(*f) == 1)
			++f;
		if (*f == 'l' || *f == 'h' || *f == 'j' || *f == 'z' || *f == 's' ||
				*f == 'd' || *f == 'i' || *f == 'D' || *f == 'u')
			f = ft_printf_3(f, print, pa);
		else if (*f == 'U' || *f == 'p' || *f == 'o' || *f == 'O' ||
				*f == 'c' || *f == 'x' || *f == 'X' || *f == 'C' || *f == 'S')
			f = ft_printf_4(f, print, pa);
		else
			percent_no_specifier(f, print);
	}
	return (f);
}
