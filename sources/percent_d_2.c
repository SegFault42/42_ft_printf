/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_d_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 13:00:54 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/08 13:01:25 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*percent_d_5(const char *f, t_printf *print, int d)
{
	if (d < 0 && *++f == '0')
	{
		if (print->zero == 1 && print->neg_sign == 0)
			ft_putchar('-');
		ft_putnbr(d * -1);
		print->zero = 1;
	}
	else if (print->point == 0)
		ft_putnbr(d);
	else if (print->point == 1 && d > 0)
	{
		ft_putnbr(d);
		print->ret += ft_strlen(ft_itoa(d));
	}
	return (f);
}
