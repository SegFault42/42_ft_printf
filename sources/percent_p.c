/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 05:33:04 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/26 06:08:07 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	percent_p(va_list pa, t_printf *print, const char *format)
{
	char	*p;
	int		i;
	int		ok;

	i = 0;
	ok = 0;
	p = va_arg(pa, char*);
	/*print->precision_space = print->space_number;*/
	if (print->precision_zero <= 0 || print->precision_space <= 0)
	{
		if (*--format == '0')
		{
			ft_putstr("0x");
			print->ret+=2;
			return ;
		}
		else
			++format;
	}
	while (*format != '%')
	{
		--format;
		++i;
	}
	++format;
	if (*format == '0')
	{
		ft_putstr("0x");
		ok = 1;
	}
	format = take_precision(format, print);
	if (*format != '0' && *format != '-')
	{
		if (*format == '0')
			ft_putstr("0x");
		write_space_char(p, print);
	}
	if (*format != '0' && ok == 0)
		ft_putstr("0x");
	if (print->precision_zero > 0)
	{
		print->precision_zero -= ft_strlen(ft_hexa_ltoa((unsigned long long)p, 0));
		while (print->precision_zero-- > 0)
		{
			ft_putchar('0');
			++print->ret;
		}
	}
	if (*format == '-')
	{
		while (print->precision_space-- > 0)
			ft_putchar(' ');
	}
		/*write_space_char(p, print);*/
	format += i -1;
	ft_putstr(ft_hexa_ltoa((unsigned long long)p, 0));
	write_space_char(p, print);
	print->ret += ft_strlen(ft_hexa_ltoa((unsigned long long)p, 0)) + 2;
}
