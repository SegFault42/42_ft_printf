/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_space_or_zero.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 03:07:15 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/08 16:11:46 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	loop_space(t_printf *print)
{
	while (print->precision_space-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
}

void	loop_zero(t_printf *print)
{
	while (print->precision_zero-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

void	while_nb_zero(int nb_zero, t_printf *print)
{
	while (nb_zero-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

void	while_space_number(t_printf *print)
{
	while (print->space_number-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
}

void	while_space(t_printf *print)
{
	while (print->space-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
}
