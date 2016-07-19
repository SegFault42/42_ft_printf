#include "../includes/ft_printf.h"

const char	*percent_d(va_list pa, t_printf *print, const char *format)
{
	int				d;
	
	/*++format;*/
	d = va_arg(pa, int);
	write_space_int(d, print);
	ft_putnbr(d);
	write_space_int(d, print);
	print->ret += ft_strlen(ft_itoa(d));
	return (format);
}
