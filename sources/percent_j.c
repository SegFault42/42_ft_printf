/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_j.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 02:55:31 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/07 02:55:33 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*percent_j(va_list pa, t_printf *print, const char *format)
{
	long			ld;
	unsigned long	l;
	long long int	lld;

	if ((*++format == 'j') && (*++format == 'd' || *format == 'i'))
	{
		lld = va_arg(pa, long long int);
		ft_put_long(lld);
		print->ret += ft_strlen(ft_ltoa(lld));
		return (format);
	}
	else if ((*format == 'j') && *++format == 'u')
	{
		l = va_arg(pa, unsigned long);
		ft_put_ulong(l);
		print->ret += ft_strlen(ft_ultoa(l));
		return (format);
	}
	else if (*format == 'd' || *format == 'i')
	{
		ld = va_arg(pa, long);
		ft_put_long(ld);
		print->ret += ft_strlen(ft_ltoa(ld));
		return (format);
	}
	else if (*format == 'D')
	{
		l = va_arg(pa, unsigned long);
		ft_put_ulong(l);
		print->ret += ft_strlen(ft_ltoa(l));
		return (format);
	}
	else if (*format == 'u')
	{
		l = va_arg(pa, unsigned long);
		ft_put_ulong(l);
		print->ret += ft_strlen(ft_ultoa(l));
		return (format);
	}
	else if (*format == 'o')
	{
		l = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa_base(l, 8));
		print->ret += ft_strlen(ft_ultoa_base(l, 8));
		return (format);
	}
	else if (*format == 'x' || *format == 'X')
	{
		l = va_arg(pa, unsigned long);
		if (*format == 'x')
			ft_putstr(ft_hexa_ltoa(l, 0));
		else if (*format == 'X')
			ft_putstr(ft_hexa_ltoa(l, 1));
		print->ret += ft_strlen(ft_hexa_ltoa(l, 0));
		return (format);
	}
	else if (*format == 'O')
	{
		l = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa_base(l, 8));
		print->ret += ft_strlen(ft_ltoa_base(l, 8));
		return (format);
	}
	else if (*format == 'U')
	{
		l = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa(l));
		print->ret += ft_strlen(ft_ultoa(l));
		return (format);
	}
	return (format);
}
