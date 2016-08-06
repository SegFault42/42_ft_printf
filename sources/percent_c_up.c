/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_c_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 09:06:04 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/06 09:06:06 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	percent_C(va_list pa, t_printf *print)
{
	wint_t	C;

	C = va_arg(pa, wint_t);
	if (C < 128)
	{
		ft_putchar(C);
		print->ret++;
	}
	else if (C < 2048)
	{
		ft_putchar(192 | (C >> 6));
		ft_putchar(128 | (C & 63));
		print->ret+=2;
	}
	else if (C < 65536)
	{
		ft_putchar(224 | (C >> 12));
		ft_putchar(128 | ((C >> 6) & 63));
		ft_putchar(128 | (C & 63));
		print->ret+=3;
	}
	else if (C < 1114112)
	{
		ft_putchar(240 | (C >> 18));
		ft_putchar(128 | ((C >> 12) & 63));
		ft_putchar(128 | ((C >> 6) & 63));
		ft_putchar(128 | (C & 63));
		print->ret+=4;
	}
}
