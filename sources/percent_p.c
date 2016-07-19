#include "../includes/ft_printf.h"

void	percent_p(va_list pa, t_printf *print)
{
	char	*p;

	p = va_arg(pa, char*);
	write_space_char(p, print);
	ft_putstr("0x");
	ft_putstr(ft_hexa_ltoa((unsigned long long)p, 0));
	write_space_char(p, print);
	print->ret += ft_strlen(ft_hexa_ltoa((unsigned long long)p, 0)) + 2;
}
