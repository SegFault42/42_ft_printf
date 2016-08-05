#include "../includes/ft_printf.h"

const char	*percent_o(va_list pa, t_printf *print, const char *format)
{
	unsigned int	o;

	++format;
	o = va_arg(pa, unsigned int);
	if (print->sharp == 1)
		--print->space_number;
	if (print->precision_zero > 0 || print->precision_space > 0)
		put_space_or_zero_o(print, o);
	if (print->space_number > 0 && print->point == 0)
		write_space_int(o, print);
	if (print->sharp == 1 && o != 0 && print->zero == 0)
	{
		ft_putchar('0');
		++print->ret;
	}
	ft_putstr(ft_ultoa_base(o, 8));
	if (print->negatif_x == 1 && print->space_number > 0 && print->point == 0)
	{
		print->space_number -= ft_strlen(ft_itoa(o));
		while (print->space_number-- > 0)
		{
			ft_putchar(' ');
			++print->ret;
		}
	}
	print->ret += ft_strlen(ft_ultoa_base(o, 8));
	return (format);
}
