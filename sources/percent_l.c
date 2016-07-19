#include "../includes/ft_printf.h"

const char	*percent_l(va_list pa, t_printf *print, const char *format)
{
	long			ld;
	unsigned long int	l;
	unsigned long int	ull;
	long long int	lld;
	wint_t	c;

	if (*++format == 'l' && (*++format == 'd' || *format == 'i' ||
		  *format == 'u' || *format == 'o' || *format == 'x' || *format == 'X'))
	{
		if (*format == 'd' || *format == 'i')
		{
			lld = va_arg(pa, long long int);
			ft_put_long(lld);
			print->ret += ft_strlen(ft_ltoa(lld));
			return (format);
		}
		else if (*format == 'u')
		{
			ull = va_arg(pa, unsigned long long int);
			ft_put_ulong(ull);
			print->ret += ft_strlen(ft_ultoa(ull));
			return (format);
		}
		else if (*format == 'o')
		{
			ull = va_arg(pa, unsigned long long int);
			ft_putstr(ft_ultoa_base(ull, 8));
			print->ret += ft_strlen(ft_ultoa_base(ull, 8));
			return (format);
		}
		else if (*format == 'x' || *format == 'X')
		{
			ull = va_arg(pa, unsigned long long int);
			if (*format == 'x')
				ft_putstr(ft_hexa_ltoa(ull, 0));
			else if (*format == 'X')
				ft_putstr(ft_hexa_ltoa(ull, 1));
			print->ret += ft_strlen(ft_hexa_ltoa(ull, 0));
			return (format);
		}
	}
	if (*format == 'u')
	{
		l = va_arg(pa, unsigned long int);
		ft_put_ulong(l);
		print->ret += ft_strlen(ft_ultoa(l));
		return (format);
	}
	else if (*format == 'd' || *format == 'i')
	{
		ld = va_arg(pa, long);
		ft_put_long(ld);
		print->ret += ft_strlen(ft_ltoa(ld));
		return (format);
	}
	else if (*format == 'D')
	{
		l = va_arg(pa, unsigned long);
		ft_put_ulong(l);
		print->ret += ft_strlen(ft_ltoa(l));
		return (format);
	}
	/*else if (*format == 'u')*/
	/*{*/
		/*l = va_arg(pa, unsigned long int);*/
		/*ft_put_ulong(l);*/
		/*print->ret += ft_strlen(ft_ltoa(l));*/
		/*return (format);*/
	/*}*/
	/*else if (*format == 'u' || *format == 'D')*/
	/*{*/
		/*l = va_arg(pa, unsigned long);*/
		/*ft_put_ulong(l);*/
		/*print->ret += ft_strlen(ft_ultoa(l));*/
		/*return (format);*/
	/*}*/
	else if (*format == 'o')
	{
		l = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa_base(l, 8));
		print->ret += ft_strlen(ft_ultoa_base(l, 8));
		return (format);
	}
	else if (*format == 'x' || *format == 'X')
	{
		l = va_arg(pa, unsigned long);
		if (*format == 'x')
			ft_putstr(ft_hexa_ltoa(l, 0));
		else if (*format == 'X')
			ft_putstr(ft_hexa_ltoa(l, 1));
		print->ret += ft_strlen(ft_hexa_ltoa(l, 0));
		return (format);
	}
	else if (*format == 'O')
	{
		l = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa_base(l, 8));
		print->ret += ft_strlen(ft_ltoa_base(l, 8));
		return (format);
	}
	else if (*format == 'U')
	{
		l = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa(l));
		print->ret += ft_strlen(ft_ultoa(l));
		return (format);
	}
	else if (*format == 'c')
	{
		percent_C(pa, print);
		return (format);
	}
	else if (*format == 's')
	{
		percent_S(pa, print);
		return (format);
	}
	/*else if ((*++format == 'l') && (*++format == 'd' || *format == 'i'))*/
	/*{*/
		/*lld = va_arg(pa, long long int);*/
		/*ft_put_long(lld);*/
		/*print->ret += ft_strlen(ft_ltoa(lld));*/
		/*return (format);*/
	/*}*/
	else if (*format == 'p')
	{
		percent_p(pa, print);
		return (format);
	}
	--format;
	return (format);
}

