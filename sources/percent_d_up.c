#include "../includes/ft_printf.h"

const char	*percent_D(va_list pa, t_printf *print, char const *format)
{
	long			d;
	unsigned int	u;

	/*++format;*/
	if (*format == 'D')
	{
		d = va_arg(pa, long);
		ft_put_long(d);
		print->ret += ft_strlen(ft_ltoa(d));
		return (format);
	}
	else if (*format == 'u')
	{
		u = va_arg(pa, unsigned int);
		ft_put_long(u);
		print->ret += ft_strlen(ft_ltoa(u));
		return (format);
	}
		return (format);
}
