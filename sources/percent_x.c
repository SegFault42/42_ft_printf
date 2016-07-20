#include "../includes/ft_printf.h"

const char	*percent_x(va_list pa, t_printf *print, const char *format)
{
	int		x;
	char	num[10];

	write_space_hex(x, print);
	x = va_arg(pa, int);
	if (*format == 'x')
		ft_putstr(ft_hexa_itoa(x, 0));
	else if (*format == 'X')
		ft_putstr(ft_hexa_itoa(x, 1));
	write_space_hex(x, print);
	print->ret += ft_strlen(ft_hexa_itoa(x, 0));
	return (format);
}

