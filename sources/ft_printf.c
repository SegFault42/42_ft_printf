/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:44:19 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/12 10:22:36 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	percent_no_specifier(const char *format, t_printf *print)
{
	char *string;

	string = ft_itoa(print->space_number);
	write_space_int_other(print, format);
	ft_putchar(*format);
	write_space_int_other(print, format);
	++print->ret;
}

const char	*check_flag(const char *format, t_printf *print)
{
	format = check_space(format, print);
	if (*format == '#')
	{
		print->sharp = 1;
		++format;
	}
	else if (*format == '+')
	{
		print->plus = 1;
		++format;
	}
	else if (*format == '0')
	{
		++format;
		if (*format != '-')
			--format;
	}
	format = check_space(format, print);
	return (format);
}

int	ft_printf(const char *format, ...)
{
	t_printf	print;
	va_list		pa;

	init_struct(&print);
	va_start(pa, format);
	if (*format == '%' && ft_strlen(format) == 1)
		return (0);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			format = check_flag(format, &print);
			format = check_neg_sign(&print, format);
			check_valid_specifier(format, &print);
			/*check_length(format, pa, &print);*/
			if (*format == '%')
				format = if_percent(format, &print);
			if (*format != '%')
			{
				if (ft_isdigit(*format) == TRUE)
					format = countSpace(format, &print);
				/*while (*format == 'l' || *format == 'h')*/
					/*++format;*/
				if (*format == 'l')
					format = percent_l(pa, &print, format);
				else if (*format == 'h')
					format = percent_h(pa, &print, format);
				else if (*format == 'j')
					format = percent_j(pa, &print, format);
				else if (*format == 'z')
					format = percent_z(pa, &print, format);
				else if (*format == 's')
					percent_s(pa, &print);
				else if (*format == 'd' || *format == 'i')
					percent_d(pa, &print, format);
				else if (*format == 'D' || *format == 'u')
					percent_D(pa, &print, format);
				else if (*format == 'U')
					percent_U(pa, &print);
				else if (*format == 'p')
					percent_p(pa, &print, format);
				else if (*format == 'o')
					percent_o(pa, &print, format);
				else if (*format == 'O')
					percent_O(pa, &print);
				else if (*format == 'c')
					format = percent_c(pa, &print, format);
				else if (*format == 'x' || *format == 'X')
					format = percent_x(pa, &print, format);
				else if (*format == 'C')
					percent_C(pa, &print);
				else if (*format == 'S')
					percent_S(pa, &print);
				else
					percent_no_specifier(format, &print);
			}
		}
		else
		{
			ft_putchar(*format);
			++print.ret;
		}
		++format;
	}
	va_end(pa);
	return (print.ret);
}
