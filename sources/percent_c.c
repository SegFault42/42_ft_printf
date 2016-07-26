#include "../includes/ft_printf.h"

const char	*percent_c(va_list pa, t_printf *print, const char *format)
{
	char	c;
	int i;

	i = 0;
	c = va_arg(pa, int);
	while (*format != '%')
	{
		--format;
		i++;
	}
	++format;
	if (ft_isdigit(*format) == TRUE)
		put_space_or_zero(print, c);
	format += i - 1;
	write_space_int(c, print);
	ft_putchar(c);
	write_space_int(c, print);
	++print->ret;
	return (format);
}
