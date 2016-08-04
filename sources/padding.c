/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 05:51:51 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/04 05:19:43 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		count_space(const char *format)
{
	char	*space;
	int		i;
	int		nb_space;
	int		j;

	j = 0;
	i = 0;
	while (ft_isdigit(*format) == 1)
	{
		format++;
		i++;
	}
	space = (char *)malloc(sizeof(char) * i);
	format -= i;
	nb_space = i * 2;
	while (i < nb_space)
	{
		space[j] = *format;
		format++;
		j++;
		i++;
	}
	nb_space = ft_atoi(space);
	free(space);
	return(nb_space);
}

void	put_space_or_zero_u(t_printf *print, unsigned int d)
{
	if (ft_strlen(ft_ltoa(d)) > print->precision_zero)
	{
		print->precision_zero -= ft_strlen(ft_ltoa(d));
		print->precision_space -= ft_strlen(ft_ltoa(d));
		print->zero = 1;
	}
	else if (ft_strlen(ft_ltoa(d)) < print->precision_zero)
	{
		print->precision_zero -= ft_strlen(ft_ltoa(d));
		print->precision_space -= ft_strlen(ft_ltoa(d)) + print->precision_zero;
		print->zero = 1;
	}
	while (print->precision_space-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
	while (print->precision_zero-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

void	put_space_or_zero_o(t_printf *print, int d)
{
	if (ft_strlen(ft_ltoa(d)) > print->precision_zero)
	{
		print->precision_zero -= ft_strlen(ft_itoa_base(d, 8));
		print->precision_space -= ft_strlen(ft_itoa_base(d, 8));
		print->zero = 1;
	}
	else if (ft_strlen(ft_ltoa(d)) < print->precision_zero)
	{
		print->precision_zero -= ft_strlen(ft_itoa_base(d, 8));
		print->precision_space -= ft_strlen(ft_itoa_base(d, 8)) + print->precision_zero;
		print->zero = 1;
	}
	while (print->precision_space-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
	while (print->precision_zero-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

void	put_space_or_zero_x(t_printf *print, int x)
{
	if (ft_strlen(ft_ltoa(x)) > print->precision_zero)
	{
		print->precision_zero -= ft_strlen(ft_hexa_itoa(x, 0));
		print->precision_space -= ft_strlen(ft_hexa_itoa(x, 0));
		print->zero = 1;
	}
	else if (ft_strlen(ft_ltoa(x)) < print->precision_zero)
	{
		print->precision_zero -= ft_strlen(ft_hexa_itoa(x, 0));
		print->precision_space -= ft_strlen(ft_hexa_itoa(x, 0)) + print->precision_zero;
		print->zero = 1;
	}
	while (print->precision_space-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
	if (print->sharp == 1)
	{
		ft_putstr("0x");
		print->ret += 2;
		print->sharp = 0;
	}
	while (print->precision_zero-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

void	put_space_or_zero_s(t_printf *print, char *s)
{
	if (ft_strlen(s) > print->precision_space)
	{
		print->precision_zero -= ft_strlen(s);
		print->precision_space -= ft_strlen(s);
		print->zero = 1;
	}
	/*else if (ft_strlen(s) < print->precision_space)*/
	/*{*/
		/*print->precision_space -= ft_strlen(s);*/
		/*print->zero = 1;*/
	/*}*/
	while (print->precision_space-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
	/*while (print->precision_zero-- > 0)*/
	/*{*/
		/*ft_putchar('0');*/
		/*++print->ret;*/
	/*}*/
}
