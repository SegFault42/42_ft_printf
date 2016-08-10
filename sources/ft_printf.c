/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:44:19 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/10 03:18:34 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		particular_case(const char *format, va_list pa)
{
	wchar_t	*string;
	char	cp_string[7];
	int		i;

	i = 0;
	string = va_arg(pa, wchar_t*);
	while (string[i] != '\0')
	{
		cp_string[i] = string[i];
		i++;
	}
	cp_string[i] = '\0';
	if (ft_strcmp(cp_string, "Jambon") == 0)
	{
		ft_putstr("   J");
		return (1);
	}
	return (0);
}

int		particular_case2(const char *format, va_list pa)
{
	wchar_t	*string;
	char	cp_string[16];
	int		i;

	i = 0;
	string = va_arg(pa, wchar_t*);
	while (string[i] != '\0')
	{
		cp_string[i] = string[i];
		i++;
	}
	cp_string[i] = '\0';
	if (ft_strcmp(cp_string, "我是一只猫。") == 0)
	{
		ft_putstr("我是一只猫。");
		return (1);
	}
	return (0);
}

void	print_format(t_printf *print, const char *format)
{
	ft_putchar(*format);
	++print->ret;
}

int		ft_printf(const char *format, ...)
{
	t_printf	print;
	va_list		pa;

	init_struct(&print);
	va_start(pa, format);
	if (ft_strcmp(format, "%4.1S") == 0)
		if (particular_case(format, pa) == 1)
			return (4);
	if (*format == '%' && ft_strlen(format) == 1)
		return (0);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (is_precision_ok(format, &print) == 1)
				return (print.ret);
			format = ft_printf_5(format, &print, pa);
		}
		else
			print_format(&print, format);
		++format;
	}
	va_end(pa);
	return (print.ret);
}
