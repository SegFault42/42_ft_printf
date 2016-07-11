/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:44:19 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/11 02:13:27 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

const char	*percent_c(va_list pa, t_printf *print, const char *format)
{
	char	c;

	c = va_arg(pa, int);
	ft_putchar(c);
	++print->ret;
	return (format);
}

const char	*percent_x(va_list pa, t_printf *print, const char *format)
{
	int				x;
	unsigned long	lx;
	char	num[10];

	if (*--format == 'l')
	{
		++format;
		x = va_arg(pa, unsigned long);
		if (*format == 'x')
			ft_putstr(ft_hexa_ltoa(x, 0));
		else if (*format == 'X')
			ft_putstr(ft_hexa_ltoa(x, 1));
		print->ret += ft_strlen(ft_hexa_ltoa(x, 0));
	}
	else
	{
		++format;
		x = va_arg(pa, int);
		if (*format == 'x')
			ft_putstr(ft_hexa_itoa(x, 0));
		else if (*format == 'X')
			ft_putstr(ft_hexa_itoa(x, 1));
		print->ret += ft_strlen(ft_hexa_itoa(x, 0));
	}
	return (format);
}

const char	*percent_d(va_list pa, t_printf *print, const char *format)
{
	int				d;
	long			ld;
	long long int	lld;

	if (*--format == 'l' && *--format == 'l')
	{
		++format;
		++format;
		lld = va_arg(pa, long long int);
		ft_put_long(lld);
		print->ret += ft_strlen(ft_ltoa(lld));
	}
	else if (*--format == 'l')
	{
		++format;
		ld = va_arg(pa, long);
		ft_put_long(ld);
		print->ret += ft_strlen(ft_ltoa(ld));
	}
	else
	{
		++format;
		d = va_arg(pa, int);
		ft_putnbr(d);
		print->ret += ft_strlen(ft_itoa(d));
	}
	return (format);
}

const char	*percent_D(va_list pa, t_printf *print, char const *format)
{
	long			d;
	unsigned long	lu;

	if (*--format == 'l')
	{
		++format;
		lu = va_arg(pa, unsigned long);
		ft_put_ulong(lu);
		print->ret += ft_strlen(ft_ultoa(lu));
	}
	else
	{
		++format;
		d = va_arg(pa, long);
		ft_put_long(d);
		print->ret += ft_strlen(ft_ltoa(d));
	}
	return (format);
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
	ft_putstr(ft_hexa_ltoa((unsigned long long)p, 0));
	print->ret += ft_strlen(ft_hexa_ltoa((unsigned long long)p, 0)) + 2;
}

const char	*percent_o(va_list pa, t_printf *print, const char *format)
{
	int				o;
	unsigned long	lo;

	if (*--format == 'l')
	{
		++format;
		lo = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa_base(lo, 8));
		print->ret += ft_strlen(ft_ultoa_base(lo, 8));
	}
	else
	{
		++format;
		o = va_arg(pa, int);
		ft_putstr(ft_itoa_base(o, 8));
		print->ret += ft_strlen(ft_itoa_base(o, 8));
	}
	return (format);
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
		&& *format != 'c' && *format != 'C' && *format != '%' && *format != 'l')
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

/*const char	*check_length(const char *format, va_list pa, t_printf *print)*/
/*{*/
	/*if (*format == 'l' && *++format == 'd')*/
	/*{*/
		/*percent_d(pa, print, format);*/
		/*++format;*/
		/*if (*format == '%')*/
		/*{*/
			/*++format;*/
			/*check_length(format, pa, print);*/
		/*}*/
		/*return(format);*/
	/*}*/
	/*else*/
		/*--format;*/
	/*return (0);*/
/*}*/

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
			/*check_length(format, pa, &print);*/
			/*printf("<%c>\n", *format);*/
			if (*format == '%' || *format == '-' || ft_isdigit(*format) == 1)
				format = if_percent(format, &print);
			if (*format != '%')
			{
				while (*format == 'l')
					++format;
				if (*format == 's')
					percent_s(pa, &print);
				else if (*format == 'd' || *format == 'i')
					percent_d(pa, &print, format);
				else if (*format == 'D' || *format == 'u')
					percent_D(pa, &print, format);
				else if (*format == 'U')
					percent_U(pa, &print);
				else if (*format == 'p')
					percent_p(pa, &print);
				else if (*format == 'o')
					percent_o(pa, &print, format);
				else if (*format == 'O')
					percent_O(pa, &print);
				else if (*format == 'c')
					format = percent_c(pa, &print, format);
				else if(*format == 'x' || *format == 'X')
					format = percent_x(pa, &print, format);
			}
		}
		else
		{
			ft_putchar(*format);
			++print.ret;
		}
		++format;
	}
	va_end(pa);
	return (print.ret);
}
