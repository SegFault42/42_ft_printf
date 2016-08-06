#include "../includes/ft_printf.h"

const char	*percent_D(va_list pa, t_printf *print, char const *format)
{
	long			d;
	unsigned int	u;

	if (print->space_number > ft_strlen(ft_ltoa(d)))
		print->space_number -= ft_strlen(ft_ltoa(d));
	if (print->zero == 1)
	{
		while (print->space_number-- > 0)
		{
			ft_putchar('0');
			++print->ret;
		}
	}
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
		if (print->precision_zero > 0 || print->precision_space > 0)
			put_space_or_zero_u(print, u);
		ft_put_long(u);
		print->ret += ft_strlen(ft_ltoa(u));
		while (print->space_number-- > 0 && print->point == 0)
		{
			ft_putchar(' ');
			++print->ret;
		}
		return (format);
	}
		return (format);
}
