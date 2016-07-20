#include "../includes/ft_printf.h"

void	percent_O(va_list pa, t_printf *print)
{
	long	o;

	o = va_arg(pa, long);
	if (print->sharp == 1 && o != 0)
	{
		ft_putchar('0');
		++print->ret;
	}
	ft_putstr(ft_ltoa_base(o, 8));
	print->ret += ft_strlen(ft_ltoa_base(o, 8));
}

