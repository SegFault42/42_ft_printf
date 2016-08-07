/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 02:54:07 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/07 05:45:53 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*percent_h(va_list pa, t_printf *print, const char *format)
{
	short int			hdi;
	unsigned short int	h;
	unsigned long		hl;
	char				hh;
	unsigned char		hhu;

	if (*++format == 'h' && (*++format == 'd' || *format == 'i' ||
		*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X'
		|| *format == 'C' || *format == 'S'))
	{
		if (*format == 'u')
		{
			hhu = va_arg(pa, int);
			ft_putnbr(hhu);
			print->ret += ft_strlen(ft_itoa(hhu));
		}
		else if (*format == 'o')
		{
			hhu = va_arg(pa, int);
			ft_putstr(ft_itoa_base(hhu, 8));
			print->ret += ft_strlen(ft_itoa_base(hhu, 8));
		}
		else if (*format == 'x' || *format == 'X')
		{
			hhu = va_arg(pa, int);
			if (*format == 'x')
				ft_putstr(ft_hexa_itoa(hhu, 0));
			else if (*format == 'X')
				ft_putstr(ft_hexa_ltoa(hhu, 1));
			print->ret += ft_strlen(ft_hexa_itoa(hhu, 0));
		}
		else if (*format == 'C')
		{
			percent_c_up(pa, print);
			return (format);
		}
		else if (*format == 'S')
		{
			percent_s_up(pa, print);
			return (format);
		}
		else
		{
			hh = va_arg(pa, int);
			ft_putnbr(hh);
			print->ret += ft_strlen(ft_itoa(hh));
		}
		return (format);
	}
	else if (*format == 'u')
	{
		h = va_arg(pa, int);
		ft_putnbr(h);
		print->ret += ft_strlen(ft_itoa(h));
		return (format);
	}
	else if (*format == 'd' || *format == 'i')
	{
		hdi = va_arg(pa, int);
		ft_putnbr(hdi);
		print->ret += ft_strlen(ft_itoa(hdi));
		return (format);
	}
	else if (*format == 'u' || *format == 'D')
	{
		h = va_arg(pa, int);
		ft_putnbr(h);
		print->ret += ft_strlen(ft_itoa(h));
		return (format);
	}
	else if (*format == 'o')
	{
		h = va_arg(pa, int);
		ft_putstr(ft_ultoa_base(h, 8));
		print->ret += ft_strlen(ft_ultoa_base(h, 8));
		return (format);
	}
	else if (*format == 'x' || *format == 'X')
	{
		h = va_arg(pa, unsigned long);
		if (*format == 'x')
			ft_putstr(ft_hexa_ltoa(h, 0));
		else if (*format == 'X')
			ft_putstr(ft_hexa_ltoa(h, 1));
		print->ret += ft_strlen(ft_hexa_ltoa(h, 0));
		return (format);
	}
	else if (*format == 'O')
	{
		h = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa_base(h, 8));
		print->ret += ft_strlen(ft_ltoa_base(h, 8));
		return (format);
	}
	else if (*format == 'U')
	{
		hl = va_arg(pa, unsigned long);
		ft_put_ulong(hl);
		print->ret += ft_strlen(ft_ultoa(hl));
		return (format);
	}
	return (format);
}
