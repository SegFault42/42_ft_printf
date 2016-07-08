/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:44:19 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/09 01:22:46 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

const char	*percent_c(va_list pa, t_printf *print, const char *format)
{
	char	c;

	c = va_arg(pa, int);
	ft_putchar(c);
	print->ret = 1;
	return (format);
}

const char	*percent_x(va_list pa, t_printf *print, const char *format)
{
	int		x;
	char	num[10];
	int		i;

	i = 0;
	x = va_arg(pa, int);
	if (*format == 'x')
		ft_putstr(ft_hexa_itoa(x, 0));
	else if (*format == 'X')
		ft_putstr(ft_hexa_itoa(x, 1));
	print->ret = ft_strlen(ft_hexa_itoa(x, 0));
	return (format);
}

void	percent_d(va_list pa, t_printf *print)
{
	int	d;

	d = va_arg(pa, int);
	ft_putnbr(d);
	print->ret += ft_strlen(ft_itoa(d));
}

void	percent_D(va_list pa, t_printf *print)
{
	long	d;

	d = va_arg(pa, long);
	ft_put_long(d);
	print->ret += ft_strlen(ft_ltoa(d));
}

void	percent_U(va_list pa, t_printf *print)
{
	unsigned long	u;

	u = va_arg(pa, unsigned long);
	ft_put_ulong(u);
	if (ft_strlen(ft_ultoa(u)) == 20)
		print->ret += 20;
	else
		print->ret += ft_strlen(ft_ultoa(u));
}

void	percent_p(va_list pa, t_printf *print)
{
	char	*p;

	p = va_arg(pa, char*);
	ft_putstr("0x");
	ft_putstr(ft_hexa_itoa((unsigned long long)p, 0));
	print->ret += ft_strlen(ft_hexa_itoa((unsigned long long)p, 0)) + 2;
}

void	percent_o(va_list pa, t_printf *print)
{
	int	o;

	o = va_arg(pa, int);
	ft_putstr(ft_itoa_base(o, 8));
	print->ret += ft_strlen(ft_itoa_base(o, 8));
}

void	percent_O(va_list pa, t_printf *print)
{
	long	o;

	o = va_arg(pa, long);
	ft_putstr(ft_ltoa_base(o, 8));
	print->ret += ft_strlen(ft_ltoa_base(o, 8));
}

void	init_struct(t_printf *printf)
{
	printf->ret = 0;
	printf->valid = 0;
}

const char	*check_valid_specifier(const char *format, t_printf *print)
{
	if (*format != 's' && *format != 'S' && *format != 'p' && *format != 'd'
		&& *format != 'D' && *format != 'i' && *format != 'o' && *format != 'O'
		&& *format != 'u' && *format != 'U' && *format != 'x' && *format != 'X'
		&& *format != 'c' && *format != 'C' && *format != '%')
	{
		if (*format != ' ')
		{
			ft_putchar(*format);
			++print->ret;
		}
		++format;
		print->valid = 1;
		return (format);
	}
	else if (*format == ' ')
	{
		while(*format == ' ')
			++format;
		return (format);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_printf	print;
	va_list		pa;

	init_struct(&print);
	va_start(pa, format);
	if (*format == '%' && ft_strlen(format) == 1)
	{
		print.ret = 0;
		return (0);
	}
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			while(*format == ' ')
				++format;
			check_valid_specifier(format, &print);
			if (*format == 's')
				percent_s(pa, &print);
			else if (*format == 'd' || *format == 'i')
				percent_d(pa, &print);
			else if (*format == 'D' || *format == 'u')
				percent_D(pa, &print);
			else if (*format == 'U')
				percent_U(pa, &print);
			else if (*format == 'p')
				percent_p(pa, &print);
			else if (*format == 'o')
				percent_o(pa, &print);
			else if (*format == 'O')
				percent_O(pa, &print);
			else if (*format == 'c')
				format = percent_c(pa, &print, format);
			else if (*format == '%' || *format == '-' || ft_isdigit(*format) == 1)
				format = if_percent(format, &print);
			else if(*format == 'x' || *format == 'X')
				format = percent_x(pa, &print, format);
			/*else if (*++format == 'd')*/
				/*printf.ret += percent_d(pa, printf.ret);*/
		}
		else
		{
			ft_putchar(*format);
			print.ret++;
		}
		format++;
	}
	va_end(pa);
	return (print.ret);
}
