#include "../includes/ft_printf.h"

const char	*percent_o(va_list pa, t_printf *print, const char *format)
{
	int				o;

	if (*format == 'O')
	{
		o = va_arg(pa, long);
		ft_putstr(ft_ltoa_base(o, 8));
		print->ret += ft_strlen(ft_ltoa_base(o, 8));
		return (format);
	}
	++format;
	o = va_arg(pa, int);
	ft_putstr(ft_itoa_base(o, 8));
	print->ret += ft_strlen(ft_itoa_base(o, 8));
	return (format);
}
