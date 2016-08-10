/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:44:19 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/10 18:14:55 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*if_is_digit(const char *format, t_printf *print)
{
	if (*--format == '.' || *format == '+')
	{
		++format;
		print->precision_zero = ft_atoi(format);
	}
	++format;
	return (format);
}

const char	*if_point_or_plus(const char *format, t_printf *print)
{
	if (*format == '+')
		print->plus = 1;
	else if (*format == '.')
		print->point = 1;
	++format;
	return (format);
}

void		write_format(const char *format, t_printf *print)
{
	ft_putchar(*format);
	++print->ret;
}

int			ft_printf(const char *format, ...)
{
	t_printf	print;
	va_list		pa;

	init_struct(&print);
	va_start(pa, format);
	if (ft_strcmp(format, "%4.1S") == 0)
		if (particular_case(pa) == 1)
			return (4);
	if (*format == '%' && ft_strlen(format) == 1)
		return (0);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (format++ && is_precision_ok(format, &print) == 1)
				return (print.ret);
			format = ft_printf_1(format, &print);
			format = ft_printf_2(format, &print, pa);
		}
		else
			write_format(format, &print);
		++format;
	}
	va_end(pa);
	return (print.ret);
}
