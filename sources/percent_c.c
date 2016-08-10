/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 05:33:08 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/10 18:09:28 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*percent_c(va_list pa, t_printf *print, const char *format)
{
	char	c;
	int		i;

	i = 0;
	c = va_arg(pa, int);
	while (*format != '%')
	{
		--format;
		i++;
	}
	++format;
	if (ft_isdigit(*format) == TRUE)
		put_space_or_zero(print, 1);
	format += i - 1;
	write_space_int(1, print);
	ft_putchar(c);
	write_space_int(1, print);
	++print->ret;
	return (format);
}
