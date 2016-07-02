/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:44:19 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/01 06:08:58 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int	percent_digit(int ret, const char *format)
{
	int	*nb;
	int	i = 0;

	while (*format != '%')
	{
		nb[i] = *format;
		i++;
		format++;
	}
	return (ret);
}

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

int	percent_x(va_list pa, int ret)
{
	int	x;

	x = va_arg(pa, int);
	ret = ft_strlen(ft_itoa_base(x, "16"));
	return ret;
}

int	percent_d(va_list pa, int ret)
{
	int	d;

	d = va_arg(pa, int);
	ft_putnbr(d);
	ret = ft_strlen(ft_itoa(d));
	return (ret);
}

int	percent_percent(const char *format, int ret)
{
	char num[10];
	int i = 0;
	int nb_char = 0;
	int	len_format;

	while (ft_isdigit(*format) == 1)
	{
		num[i] = *format;
		format++;
		i++;
	}
	num[i] = 'a';
	nb_char = ft_atoi(num);
	len_format = ft_strclen(format, '%') + 1;
	while (len_format < nb_char--)
	{
		ft_putchar(' ');
		ret++;
	}
	if (format[0] != '-')
	{
		ft_putchar('%');
		ret++;
	}
	return (ret);
}

int	percent_percent_neg(const char *format, int ret)
{
	char num[10];
	int i = 0;
	int nb_char = 0;
	int	len_format;

	while (ft_isdigit(*format) == 1)
	{
		num[i] = *format;
		format++;
		i++;
	}
	num[i] = 'a';
	nb_char = ft_atoi(num);
	len_format = ft_strclen(format, '%') + 1;
	ft_putchar('%');
	format++;
	ret++;
	while (len_format < nb_char--)
	{
		ft_putchar(' ');
		ret++;
	}

	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	pa;
	int		n;
	char	*s;
	char	c;
	int ret = 0;

	n = 0;
	va_start(pa, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			while (*format == ' ')
				format++;
			if (*format == '%' || *format == '-' || ft_isdigit(*format) == 1)
			{
				if (*format == '-')
				{
					format++;
					ret += percent_percent_neg(format, ret);
					while (ft_isdigit(*format) == 1)
						format++;
				}
				else
				{
					ret += percent_percent(format, ret);
					while (ft_isdigit(*format) == 1)
						format++;
				}
			}
			/*else if (*++format == 's')*/
				/*ret += percent_s(pa, ret);*/
			/*else if (*++format == 'c')*/
				/*ret += percent_c(pa, ret);*/
			/*else if (*++format == 'd')*/
				/*ret += percent_d(pa, ret);*/
			/*else if(*++format == 'x')*/
				/*ret += percent_x(pa, ret);*/
		}
		else
		{
			ft_putchar(*format);
			ret ++;
		}
		format++;
	}
	va_end(pa);
	return (ret);
}
