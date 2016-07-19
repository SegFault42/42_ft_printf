#include "../includes/ft_printf.h"

const char	*check_valid_specifier(const char *format, t_printf *print)
{
	if (*format != 's' && *format != 'S' && *format != 'p' && *format != 'd'
		&& *format != 'D' && *format != 'i' && *format != 'o' && *format != 'O'
		&& *format != 'u' && *format != 'U' && *format != 'x' && *format != 'X'
		&& *format != 'c' && *format != 'C' && *format != '%' && *format != 'l'
		&& *format != 'h' && *format != 'j' && *format != 'z' && *format != 'C'
		&& *format != 'S' && ft_isdigit(*format) == 0)
	{
		/*if (*format != ' ')*/
		/*{*/
			/*ft_putchar(*format);*/
			/*++print->ret;*/
		/*}*/
		/*++format;*/
		/*print->valid = 1;*/
		/*return (format);*/
	}
	else if (*format == ' ')
	{
		while(*format == ' ')
			++format;
		return (format);
	}
	return (0);
}

const char *countSpace(const char *format, t_printf *print)
{
	char	*string;
	int		i = 0;
	int		j = 0;

	if (ft_isdigit(*format) == TRUE)
	{
		while (ft_isdigit(*format) == TRUE)
		{
			i++;
			++format;
		}
		format -= i;
		string = (char *)malloc(sizeof(char) * (i + 1));
		while (i--)
		{
			string[j] = format[j];
			j++;
		}
		string[j] = '\0';
	}
	print->space_number = ft_atoi(string);
	format += ft_strlen(string);
	/*free(string);*/
	/*return (nb_space);*/
	return (format);
}

const char	*check_neg_sign(t_printf *print, const char *format)
{
	if (*format == '-')
	{
		print->negatif = 1;
		++format;
	}
	return (format);
}
