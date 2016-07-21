#include "../includes/ft_printf.h"

const char	*percent_d(va_list pa, t_printf *print, const char *format)
{
	int				d;
	int				i;

	i = 0;
	d = va_arg(pa, int);
	print->d = d;
	write_space_int(d, print);
	if (d >= 0 && print->plus == 0)
	{
		while (print->space)
		{
			ft_putchar(' ');
			++print->ret;
			--print->space;
		}
	}
	if (print->plus == 1 && d >= 0)
	{
		ft_putchar('+');
		++print->ret;
	}
	while (*format != '%')
	{
		--format;
		i++;
	}
	if (d < 0 && *++format == '0')
	{
		ft_putnbr(d * -1);
		print->zero = 1;
	}
	else
		ft_putnbr(d);
	format+=(i - 1);
	write_space_int(d, print);
	print->ret += ft_strlen(ft_itoa(d));
	return (format);
}
