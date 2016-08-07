/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_d_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 09:01:45 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/07 02:49:05 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static const char	*percent_d_up_1(va_list pa, t_printf *print, char const *f)
{
	unsigned int	u;

	u = va_arg(pa, unsigned int);
	if (print->precision_zero > 0 || print->precision_space > 0)
		put_space_or_zero_u(print, u);
	ft_put_long(u);
	print->ret += ft_strlen(ft_ltoa(u));
	while (print->space_number-- > 0 && print->point == 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
	return (f);
}

const char			*percent_d_up(va_list pa, t_printf *print, char const *f)
{
	long	d;

	if (print->space_number > ft_strlen(ft_ltoa(d)))
		print->space_number -= ft_strlen(ft_ltoa(d));
	if (print->zero == 1)
	{
		while (print->space_number-- > 0)
		{
			ft_putchar('0');
			++print->ret;
		}
	}
	if (*f == 'D')
	{
		d = va_arg(pa, long);
		ft_put_long(d);
		print->ret += ft_strlen(ft_ltoa(d));
		return (f);
	}
	else if (*f == 'u')
		percent_d_up_1(pa, print, f);
	return (f);
}
