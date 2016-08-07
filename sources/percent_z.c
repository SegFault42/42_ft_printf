/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 05:01:45 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/07 05:08:46 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*percent_z(va_list pa, t_printf *print, const char *format)
{
	unsigned long	z;

	if (*++format == 'd' || *format == 'i')
	{
		z = va_arg(pa, size_t);
		ft_put_long(z);
		print->ret += ft_strlen(ft_ltoa(z));
		return (format);
	}
	else if (*format == 'u' || *format == 'D')
	{
		z = va_arg(pa, size_t);
		ft_put_ulong(z);
		print->ret += ft_size_ttoa(z);
		return (format);
	}
	else if (*format == 'o')
	{
		z = va_arg(pa, size_t);
		ft_putstr(ft_ultoa_base(z, 8));
		print->ret += ft_strlen(ft_ultoa_base(z, 8));
		return (format);
	}
	else if (*format == 'x' || *format == 'X')
	{
		z = va_arg(pa, size_t);
		if (*format == 'x')
			ft_putstr(ft_hexa_ltoa(z, 0));
		else if (*format == 'X')
			ft_putstr(ft_hexa_ltoa(z, 1));
		print->ret += ft_strlen(ft_hexa_ltoa(z, 0));
		return (format);
	}
	else if (*format == 'O')
	{
		z = va_arg(pa, size_t);
		ft_putstr(ft_ultoa_base(z, 8));
		print->ret += ft_strlen(ft_ltoa_base(z, 8));
		return (format);
	}
	else if (*format == 'U')
	{
		z = va_arg(pa, size_t);
		ft_putstr(ft_ultoa(z));
		print->ret += ft_strlen(ft_ultoa(z));
		return (format);
	}
	return (format);
}
