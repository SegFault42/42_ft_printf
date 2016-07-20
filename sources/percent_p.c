#include "../includes/ft_printf.h"

void	percent_p(va_list pa, t_printf *print, const char *format)
{
	char	*p;
	int		i;

	i = 0;
	p = va_arg(pa, char*);
	while (*format != '%')
	{
		--format;
		++i;
	}
	if (*format == '%' && *format++ != '0' && *format != '-')
	{
		if (*format == '0')
			ft_putstr("0x");
		write_space_char(p, print);
	}
	if (*format != '0')
		ft_putstr("0x");
	if (*format == '-')
		write_space_char(p, print);
	format += i -1;
	ft_putstr(ft_hexa_ltoa((unsigned long long)p, 0));
	write_space_char(p, print);
	print->ret += ft_strlen(ft_hexa_ltoa((unsigned long long)p, 0)) + 2;
}
