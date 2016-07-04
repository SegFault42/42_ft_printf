#include "./includes/ft_printf.h"
#include <stdio.h>

int	if_percent(const char *format, int ret)
{
	/*if (*format == '%' || *format == '-' || ft_isdigit(*format) == 1)*/
	/*{*/
		if (*format == '-')
		{
			format++;
			ret += percent_percent_neg(format, ret);
			while (ft_isdigit(*format) == 1)
				format++;
		}
		else
		{
			ret += percent_percent(format, ret);
			while (ft_isdigit(*format) == 1)
				format++;
		}
	return (ret);
}

int	percent_percent(const char *format, int ret)
{
	char num[10];
	int i = 0;
	int nb_char = 0;
	int	len_format;

	while (ft_isdigit(*format) == 1)
	{
		num[i] = *format;
		format++;
		i++;
	}
	num[i] = 'a';
	nb_char = ft_atoi(num);
	len_format = ft_strclen(format, '%') + 1;
	while (len_format < nb_char--)
	{
		ft_putchar(' ');
		ret++;
	}
	if (format[0] != '-')
	{
		ft_putchar('%');
		ret++;
	}
	return (ret);
}

int	percent_percent_neg(const char *format, int ret)
{
	char num[10];
	int i = 0;
	int nb_char = 0;
	int	len_format;

	while (ft_isdigit(*format) == 1)
	{
		num[i] = *format;
		format++;
		i++;
	}
	num[i] = 'a';
	nb_char = ft_atoi(num);
	len_format = ft_strclen(format, '%') + 1;
	ft_putchar('%');
	ret++;
	format++;
	while (len_format < nb_char--)
	{
		ft_putchar(' ');
		ret++;
	}
	return (ret);
}
