#include "../includes/ft_printf.h"

const char	*percent_x(va_list pa, t_printf *print, const char *format)
{
	int				x;
	/*unsigned long	lx;*/
	char	num[10];

	/*if (*--format == 'l')*/
	/*{*/
		/*++format;*/
		/*x = va_arg(pa, unsigned long);*/
		/*if (*format == 'x')*/
			/*ft_putstr(ft_hexa_ltoa(x, 0));*/
		/*else if (*format == 'X')*/
			/*ft_putstr(ft_hexa_ltoa(x, 1));*/
		/*print->ret += ft_strlen(ft_hexa_ltoa(x, 0));*/
	/*}*/
	/*else*/
	/*{*/
		x = va_arg(pa, int);
		if (*format == 'x')
			ft_putstr(ft_hexa_itoa(x, 0));
		else if (*format == 'X')
			ft_putstr(ft_hexa_itoa(x, 1));
		print->ret += ft_strlen(ft_hexa_itoa(x, 0));
	/*}*/
	return (format);
}

