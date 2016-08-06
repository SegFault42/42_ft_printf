/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 09:20:53 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/07 01:18:55 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*check_valid_specifier(const char *format, t_printf *print)
{
	if (*format != 's' && *format != 'S' && *format != 'p' && *format != 'd'
		&& *format != 'D' && *format != 'i' && *format != 'o' && *format != 'O'
		&& *format != 'u' && *format != 'U' && *format != 'x' && *format != 'X'
		&& *format != 'c' && *format != 'C' && *format != '%' && *format != 'l'
		&& *format != 'h' && *format != 'j' && *format != 'z' && *format != 'C'
		&& *format != 'S' && ft_isdigit(*format) == 0)
		return (0);
	else if (*format == ' ')
	{
		while (*format == ' ')
			++format;
		return (format);
	}
	return (0);
}

const char	*check_space(const char *format, t_printf *print)
{
	while (*format == ' ')
	{
		++format;
		++print->space;
	}
	return (format);
}

const char	*count_espace(const char *format, t_printf *print)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_isdigit(*format) == TRUE)
	{
		struct_is_zero(print, format);
		--format;
		while (ft_isdigit(*++format) == TRUE)
			i++;
		format -= i;
		string = (char *)malloc(sizeof(char) * (i + 1));
		while (i--)
		{
			string[j] = format[j];
			j++;
		}
		string[j] = '\0';
		print->space_number = ft_atoi(string);
		format += ft_strlen(string);
		free(string);
	}
	return (format);
}

const char	*check_neg_sign(t_printf *print, const char *format)
{
	if (*format == '-')
	{
		print->negatif = 1;
		print->negatif_x = 1;
		++format;
	}
	return (format);
}
