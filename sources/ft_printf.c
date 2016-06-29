/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:44:19 by rabougue          #+#    #+#             */
/*   Updated: 2016/06/29 19:35:58 by rabougue         ###   ########.fr       */
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

int	percent_percent(int ret)
{
	ft_putchar('%');
	ret++;
	return (ret);
}

int	percent_c(va_list pa, int ret)
{
	char	c;

	c = va_arg(pa, int);
	ft_putchar(c);
	ret++;
	return (ret);
}

int	percent_s(va_list pa, int ret)
{
	char	*s;

	s = va_arg(pa, char*);
	ft_putstr(s);
	ret += ft_strlen(s);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	pa;
	int		n;
	char	*s;
	char	c;
	int ret = 0;

	va_start(pa, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*++format == 's')
				ret += percent_s(pa, ret);
			if (*++format == '%')
				ret += percent_percent(ret);
			else if (*++format == 'c')
				ret += percent_c(pa, ret);
		}
		else
		{
			ft_putchar(*format);
			ret++;
		}
		format++;
	}
	va_end(pa);
	return (ret);
}
