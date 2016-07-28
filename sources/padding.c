/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 05:51:51 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/06 05:52:16 by rabougue         ###   ########.fr       */
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
	/*if (print->precision_space > 0)*/
		/*print->precision_space -= print->precision_zero;*/
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
		/*print->precision_space -= print->precision_zero;*/
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
