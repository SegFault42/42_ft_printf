/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_space_or_zero_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:11:29 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/09 16:30:05 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	loop_space_no_ret(t_printf *print)
{
	while (print->precision_space-- > 0)
		ft_putchar(' ');
}

void	while_precision_space(t_printf *print)
{
	while (print->precision_space-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

void	while_space_number_zero(t_printf *print)
{
	while (print->space_number-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

void	write_null(t_printf *print)
{
	ft_putstr("(null)");
	print->ret += 6;
}

void	space_number_inf(t_printf *print)
{
	while (--print->precision_space > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
}
