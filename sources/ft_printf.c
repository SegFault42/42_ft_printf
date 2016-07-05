/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:44:19 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/05 06:34:09 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int	percent_c(va_list pa, int ret)
{
	char	c;

	c = va_arg(pa, int);
	ft_putchar(c);
	ret = 1;
	return (ret);
}

int	percent_s(va_list pa, int ret)
{
	char	*s;

	s = va_arg(pa, char*);
	ret = ft_strlen(s);
	return (ret);
}

const char	*percent_x(va_list pa, t_printf *printf, const char *format)
{
	int	x;

	x = va_arg(pa, int);
	if (*format == 'x')
		ft_putstr(ft_hexa_itoa(x, 0));
	else if (*format == 'X')
		ft_putstr(ft_hexa_itoa(x, 1));
	printf->ret = ft_strlen(ft_hexa_itoa(x, 0));
	return (format);
}

int	percent_d(va_list pa, int ret)
{
	int	d;

	d = va_arg(pa, int);
	ft_putnbr(d);
	ret = ft_strlen(ft_itoa(d));
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	t_printf	printf;
	va_list		pa;
	char		*s;
	char		c;
	printf.ret = 0;

	va_start(pa, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			while (*format == ' ')
				format++;
			if (*format == '%' || *format == '-' || ft_isdigit(*format) == 1)
				format = if_percent(format, &printf);
			else if(*format == 'x' || *format == 'X')
				format = percent_x(pa, &printf, format);
			/*else if (*++format == 's')*/
				/*printf.ret += percent_s(pa, printf.ret);*/
			/*else if (*++format == 'c')*/
				/*printf.ret += percent_c(pa, printf.ret);*/
			/*else if (*++format == 'd')*/
				/*printf.ret += percent_d(pa, printf.ret);*/
		}
		else
		{
			ft_putchar(*format);
			printf.ret++;
		}
		format++;
	}
	va_end(pa);
	return (printf.ret);
}
