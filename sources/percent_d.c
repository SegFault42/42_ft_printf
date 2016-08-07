/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 00:56:11 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/07 13:13:35 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			space_zero(t_printf *print, const char *format, int d)
{
	int	i;
	int	nb_zero;

	i = 0;
	while (*format != '%')
	{
		--format;
		i++;
	}
	if (*++format == ' ' && *++format == '0')
	{
		ft_putchar(' ');
		++print->ret;
		while (*format == '0')
			++format;
		if (ft_isdigit(*format) == TRUE)
		{
			nb_zero = ft_atoi(format) - ft_strlen(ft_itoa(d)) - 1;
			while (nb_zero > 0)
			{
				ft_putchar('0');
				nb_zero--;
				++print->ret;
			}
			ft_putnbr(d);
			print->ret += ft_strlen(ft_itoa(d));
			return (1);
		}
	}
	return (0);
}

void		put_space_or_zero(t_printf *print, int d)
{
	if (ft_strlen(ft_itoa(d)) > print->precision_zero)
	{
		print->precision_space -= ft_strlen(ft_itoa(d));
		print->space = 1;
	}
	else if (ft_strlen(ft_itoa(d)) < print->precision_zero)
	{
		if (d < 0)
			print->precision_space -= print->precision_zero + 1;
		else
			print->precision_space -= print->precision_zero;
		print->zero = 1;
	}
	if (d < 0)
		print->precision_zero -= ft_strlen(ft_itoa(d)) - 1;
	else
		print->precision_zero -= ft_strlen(ft_itoa(d));
	while (print->precision_space-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
	if (d < 0)
		ft_putchar('-');
	while (print->precision_zero-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

const char	*percent_d(va_list pa, t_printf *print, const char *format)
{
	int				d;
	int				i;
	int				neg_sign;
	int				z;
	int				dd;

	i = 0;
	d = va_arg(pa, int);
	dd = print->d;
	print->d = d;
	neg_sign = 0;
	z = 0;
	if (d < 0 && print->point == 1)
		--print->space_number;
	if (print->space_number > print->precision_zero)
		z = 1;
	if (print->space_number > 0)
		neg_sign = 1;
	if (d < 0 && print->plus == 1)
		print->precision_zero--;
	if (print->space_number > 0 && print->precision_zero > 0 &&
			print->negatif == 0)
	{
		print->space_number -= print->precision_zero;
		if (print->plus == 1)
			--print->space_number;
		while (print->space_number-- > 0)
		{
			ft_putchar(' ');
			++print->ret;
		}
	}
	if (print->plus == 1 && print->precision_zero > 0 && d > 0)
	{
		ft_putchar('+');
		if (print->negatif == 1)
			--print->space_number;
		if (z == 0)
			--print->precision_zero;
		++print->ret;
	}
	if (print->precision_zero > 0 || print->precision_space > 0)
	{
		put_space_or_zero(print, d);
		if (dd == 1 && print->point == 1)
			ft_putchar(' ');
		else if (d < 0)
			ft_putnbr(d * -1);
		else
			ft_putnbr(d);
		if (print->negatif == 1)
		{
			print->space_number -= (ft_strlen(ft_itoa(d))
					- print->precision_zero);
			while (print->space_number-- > 0)
			{
				ft_putchar(' ');
				++print->ret;
			}
		}
		print->ret += ft_strlen(ft_itoa(d));
		return (format);
	}
	if (space_zero(print, format, d) == 1)
		return (format);
	if (print->plus == 0 && print->point != 1)
		write_space_int(d, print);
	if (print->point == 1)
		format = precision(format, d, print);
	if (d >= 0 && print->plus == 0)
	{
		while (print->space)
		{
			ft_putchar(' ');
			++print->ret;
			--print->space;
		}
	}
	if (print->plus == 1 && d >= 0)
	{
		ft_putchar('+');
		++print->ret;
	}
	while (*format != '%')
	{
		--format;
		i++;
	}
	if (d < 0 && *++format == '0')
	{
		if (print->zero == 1 && neg_sign == 0)
			ft_putchar('-');
		ft_putnbr(d * -1);
		print->zero = 1;
	}
	else
		ft_putnbr(d);
	format += (i - 1);
	write_space_int(d, print);
		print->ret += ft_strlen(ft_itoa(d));
	return (format);
}
