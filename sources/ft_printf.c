/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:44:19 by rabougue          #+#    #+#             */
/*   Updated: 2016/06/29 15:47:43 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list pa;
	int		n;
	char	*s;
	char	c;
	float	f;
	int ret = 0;

	va_start(pa, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*++format == '%')
			{
				ft_putchar('%');
				ret++;
			}
			else if (*++format == 'c')
			{
				c = va_arg(pa, int);
				ft_putchar(c);
				ret++;
			}
		}
		else
		ft_putchar(*format);
		format++;
		ret++;
	}
	va_end(pa);
	return (ret);
}
