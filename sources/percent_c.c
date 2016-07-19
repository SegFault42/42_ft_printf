#include "../includes/ft_printf.h"

const char	*percent_c(va_list pa, t_printf *print, const char *format)
{
	char	c;

	c = va_arg(pa, int);
	write_space_int(c, print);
	ft_putchar(c);
	write_space_int(c, print);
	++print->ret;
	return (format);
}
