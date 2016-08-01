#include "../includes/ft_printf.h"

const char	*percent_o(va_list pa, t_printf *print, const char *format)
{
	unsigned int	o;

	/*if (*format == 'O')*/
	/*{*/
		/*o = va_arg(pa, long);*/
		/*ft_putstr(ft_ltoa_base(o, 8));*/
		/*print->ret += ft_strlen(ft_ltoa_base(o, 8));*/
		/*return (format);*/
	/*}*/
	++format;
	o = va_arg(pa, unsigned int);
	/*if (print->point == 1)*/
		/*print->precision_zero -= ft_strlen(format);*/
	if (print->precision_zero > 0 || print->precision_space > 0)
		put_space_or_zero_o(print, o);
	if (print->sharp == 1 && print->zero == 1 && print->zero == 1)
	{
	}
	else if (print->sharp == 1 && o != 0)
	{
		ft_putchar('0');
		++print->ret;
	}
	ft_putstr(ft_ultoa_base(o, 8));
	print->ret += ft_strlen(ft_ultoa_base(o, 8));
	return (format);
}
