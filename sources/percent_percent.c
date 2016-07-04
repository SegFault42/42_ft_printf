#include "./includes/ft_printf.h"
#include <stdio.h>

const char	*if_percent(const char *format, t_printf *printf)
{
	if (*format == '-')
	{
		format++;
		percent_percent_neg(format, printf);
		while (ft_isdigit(*format) == 1)
			format++;
	}
	else
	{
		percent_percent(format, printf);
		while (ft_isdigit(*format) == 1)
			format++;
	}
	return (format);
}

const char	*percent_percent(const char *format, t_printf *printf)
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
		printf->ret++;
	}
	if (format[0] != '-')
	{
		ft_putchar('%');
		printf->ret++;
	}
	return (format);
}

const char	*percent_percent_neg(const char *format, t_printf *printf)
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
	printf->ret++;
	format++;
	while (len_format < nb_char--)
	{
		ft_putchar(' ');
		printf->ret++;
	}
	return (format);
}
