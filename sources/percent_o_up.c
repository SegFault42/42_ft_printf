#include "../includes/ft_printf.h"

void	percent_O(va_list pa, t_printf *print)
{
	long	o;

	o = va_arg(pa, long);
	ft_putstr(ft_ltoa_base(o, 8));
	print->ret += ft_strlen(ft_ltoa_base(o, 8));
}

