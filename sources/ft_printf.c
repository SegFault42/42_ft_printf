/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:44:19 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/12 10:22:36 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

const char	*percent_c(va_list pa, t_printf *print, const char *format)
{
	char	c;

	c = va_arg(pa, int);
	write_space_int(c, print);
	ft_putchar(c);
	++print->ret;
	return (format);
}

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

const char	*percent_l(va_list pa, t_printf *print, const char *format)
{
	long			ld;
	unsigned long int	l;
	unsigned long int	ull;
	long long int	lld;

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
	/*else if ((*++format == 'l') && (*++format == 'd' || *format == 'i'))*/
	/*{*/
		/*lld = va_arg(pa, long long int);*/
		/*ft_put_long(lld);*/
		/*print->ret += ft_strlen(ft_ltoa(lld));*/
		/*return (format);*/
	/*}*/
	--format;
	return (format);
}

const char	*percent_j(va_list pa, t_printf *print, const char *format)
{
	long			ld;
	unsigned long	l;
	long long int	lld;

	if ((*++format == 'j') && (*++format == 'd' || *format == 'i'))
	{
		lld = va_arg(pa, long long int);
		ft_put_long(lld);
		print->ret += ft_strlen(ft_ltoa(lld));
		return (format);
	}
	else if ((*format == 'j') && *++format == 'u')
	{
		l = va_arg(pa, unsigned long);
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
	else if (*format == 'u')
	{
		l = va_arg(pa, unsigned long);
		ft_put_ulong(l);
		print->ret += ft_strlen(ft_ultoa(l));
		return (format);
	}
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
	return (format);
}

const char	*percent_h(va_list pa, t_printf *print, const char *format)
{
	short int			hdi;
	unsigned short int	h;
	char				hh;
	unsigned char		hhu;

	if (*++format == 'h' && (*++format == 'd' || *format == 'i' ||
		  *format == 'u' || *format == 'o' || *format == 'x' || *format == 'X'))
	{
		if (*format == 'u')
		{
			hhu = va_arg(pa, int);
			ft_putnbr(hhu);
			print->ret += ft_strlen(ft_itoa(hhu));
		}
		else if (*format == 'o')
		{
			hhu = va_arg(pa, int);
			ft_putstr(ft_itoa_base(hhu, 8));
			print->ret += ft_strlen(ft_itoa_base(hhu, 8));
		}
		else if (*format == 'x' || *format == 'X')
		{
		hhu = va_arg(pa, int);
		if (*format == 'x')
			ft_putstr(ft_hexa_itoa(hhu, 0));
		else if (*format == 'X')
			ft_putstr(ft_hexa_ltoa(hhu, 1));
		print->ret += ft_strlen(ft_hexa_itoa(hhu, 0));
		}
		else
		{
			hh = va_arg(pa, int);
			ft_putnbr(hh);
			print->ret += ft_strlen(ft_itoa(hh));
		}
		return (format);
	}
	else if (*format == 'u')
	{
		h = va_arg(pa, int);
		ft_putnbr(h);
		print->ret += ft_strlen(ft_itoa(h));
		return (format);
	}
	else if (*format == 'd' || *format == 'i')
	{
		hdi = va_arg(pa, int);
		ft_putnbr(hdi);
		print->ret += ft_strlen(ft_itoa(hdi));
		return (format);
	}
	else if (*format == 'u' || *format == 'D')
	{
		h = va_arg(pa, int);
		ft_putnbr(h);
		print->ret += ft_strlen(ft_itoa(h));
		return (format);
	}
	else if (*format == 'o')
	{
		h = va_arg(pa, int);
		ft_putstr(ft_ultoa_base(h, 8));
		print->ret += ft_strlen(ft_ultoa_base(h, 8));
		return (format);
	}
	else if (*format == 'x' || *format == 'X')
	{
		h = va_arg(pa, unsigned long);
		if (*format == 'x')
			ft_putstr(ft_hexa_ltoa(h, 0));
		else if (*format == 'X')
			ft_putstr(ft_hexa_ltoa(h, 1));
		print->ret += ft_strlen(ft_hexa_ltoa(h, 0));
		return (format);
	}
	else if (*format == 'O')
	{
		h = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa_base(h, 8));
		print->ret += ft_strlen(ft_ltoa_base(h, 8));
		return (format);
	}
	else if (*format == 'U')
	{
		h = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa(h));
		print->ret += ft_strlen(ft_ultoa(h));
		return (format);
	}
	return(format);
}

const char	*percent_z(va_list pa, t_printf *print, const char *format)
{
	unsigned long	z;

	/*if ((*++format == 'z') && (*++format == 'd' || *format == 'i'))*/
	/*{*/
		/*lld = va_arg(pa, long long int);*/
		/*ft_put_long(lld);*/
		/*print->ret += ft_strlen(ft_ltoa(lld));*/
		/*return (format);*/
	/*}*/
	/*if ((*format == 'z') && *++format == 'u')*/
	/*{*/
		/*z = va_arg(pa, size_t);*/
		/*ft_put_ulong(z);*/
		/*print->ret += ft_strlen(ft_ultoa(z));*/
		/*return (format);*/
	/*}*/
	if (*++format == 'd' || *format == 'i')
	{
		z = va_arg(pa, size_t);
		ft_put_long(z);
		print->ret += ft_strlen(ft_ltoa(z));
		return (format);
	}
	else if (*format == 'u' || *format == 'D')
	{
		z = va_arg(pa, size_t);
		ft_put_ulong(z);
		print->ret += ft_size_ttoa(z);
		return (format);
	}
	else if (*format == 'o')
	{
		z = va_arg(pa, size_t);
		ft_putstr(ft_ultoa_base(z, 8));
		print->ret += ft_strlen(ft_ultoa_base(z, 8));
		return (format);
	}
	else if (*format == 'x' || *format == 'X')
	{
		z = va_arg(pa, size_t);
		if (*format == 'x')
			ft_putstr(ft_hexa_ltoa(z, 0));
		else if (*format == 'X')
			ft_putstr(ft_hexa_ltoa(z, 1));
		print->ret += ft_strlen(ft_hexa_ltoa(z, 0));
		return (format);
	}
	else if (*format == 'O')
	{
		z = va_arg(pa, size_t);
		ft_putstr(ft_ultoa_base(z, 8));
		print->ret += ft_strlen(ft_ltoa_base(z, 8));
		return (format);
	}
	else if (*format == 'U')
	{
		z = va_arg(pa, size_t);
		ft_putstr(ft_ultoa(z));
		print->ret += ft_strlen(ft_ultoa(z));
		return (format);
	}
	return (format);
}

const char	*percent_d(va_list pa, t_printf *print, const char *format)
{
	int				d;
	
	++format;
	d = va_arg(pa, int);
	write_space_int(d, print);
	ft_putnbr(d);
	print->ret += ft_strlen(ft_itoa(d));
	return (format);
}

const char	*percent_D(va_list pa, t_printf *print, char const *format)
{
	long			d;

	++format;
	d = va_arg(pa, long);
	ft_put_long(d);
	print->ret += ft_strlen(ft_ltoa(d));
	return (format);
}

void	percent_U(va_list pa, t_printf *print)
{
	unsigned long	u;

	u = va_arg(pa, unsigned long);
	ft_put_ulong(u);
	if (ft_strlen(ft_ultoa(u)) == 20)
		print->ret += 20;
	else
		print->ret += ft_strlen(ft_ultoa(u));
}

void	percent_p(va_list pa, t_printf *print)
{
	char	*p;

	p = va_arg(pa, char*);
	write_space_char(p, print);
	ft_putstr("0x");
	ft_putstr(ft_hexa_ltoa((unsigned long long)p, 0));
	print->ret += ft_strlen(ft_hexa_ltoa((unsigned long long)p, 0)) + 2;
}

const char	*percent_o(va_list pa, t_printf *print, const char *format)
{
	int				o;

	if (*format == 'O')
	{
		o = va_arg(pa, long);
		ft_putstr(ft_ltoa_base(o, 8));
		print->ret += ft_strlen(ft_ltoa_base(o, 8));
		return (format);
	}
	++format;
	o = va_arg(pa, int);
	ft_putstr(ft_itoa_base(o, 8));
	print->ret += ft_strlen(ft_itoa_base(o, 8));
	return (format);
}

void	percent_O(va_list pa, t_printf *print)
{
	long	o;

	o = va_arg(pa, long);
	ft_putstr(ft_ltoa_base(o, 8));
	print->ret += ft_strlen(ft_ltoa_base(o, 8));
}

void	init_struct(t_printf *printf)
{
	printf->ret = 0;
	printf->valid = 0;
	printf->space_number = 0;
}

const char	*check_valid_specifier(const char *format, t_printf *print)
{
	if (*format != 's' && *format != 'S' && *format != 'p' && *format != 'd'
		&& *format != 'D' && *format != 'i' && *format != 'o' && *format != 'O'
		&& *format != 'u' && *format != 'U' && *format != 'x' && *format != 'X'
		&& *format != 'c' && *format != 'C' && *format != '%' && *format != 'l'
		&& *format != 'h' && *format != 'j' && *format != 'z' && ft_isdigit(*format) == 0)
	{
		if (*format != ' ')
		{
			ft_putchar(*format);
			++print->ret;
		}
		++format;
		print->valid = 1;
		return (format);
	}
	else if (*format == ' ')
	{
		while(*format == ' ')
			++format;
		return (format);
	}
	return (0);
}

/*const char	*check_length(const char *format, va_list pa, t_printf *print)*/
/*{*/
	/*if (*format == 'l' && *++format == 'd')*/
	/*{*/
		/*percent_d(pa, print, format);*/
		/*++format;*/
		/*if (*format == '%')*/
		/*{*/
			/*++format;*/
			/*check_length(format, pa, print);*/
		/*}*/
		/*return(format);*/
	/*}*/
	/*else*/
		/*--format;*/
	/*return (0);*/
/*}*/
const char *countSpace(const char *format, t_printf *print)
{
	char *string;
	int i = 0;
	int j = 0;

	if (ft_isdigit(*format) == TRUE)
	{
		while (ft_isdigit(*format) == TRUE)
		{
			i++;
			++format;
		}
		format -= i;
		string = (char *)malloc(sizeof(char) * (i + 1));
		while (i--)
		{
			string[j] = format[j];
			j++;
		}
		string[j] = '\0';
	}
	print->space_number = ft_atoi(string);
	format += ft_strlen(string);
	/*free(string);*/
	/*return (nb_space);*/
	return (format);
}

int	ft_printf(const char *format, ...)
{
	t_printf	print;
	va_list		pa;

	init_struct(&print);
	va_start(pa, format);
	if (*format == '%' && ft_strlen(format) == 1)
		return (0);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			while(*format == ' ')
				++format;
			check_valid_specifier(format, &print);
			/*check_length(format, pa, &print);*/
			if (*format == '%' || *format == '-')
				format = if_percent(format, &print);
			if (*format != '%')
			{
				if (ft_isdigit(*format) == TRUE)
					format = countSpace(format, &print);
				/*while (*format == 'l' || *format == 'h')*/
					/*++format;*/
				if (*format == 'l')
					format = percent_l(pa, &print, format);
				else if (*format == 'h')
					format = percent_h(pa, &print, format);
				else if (*format == 'j')
					format = percent_j(pa, &print, format);
				else if (*format == 'z')
					format = percent_z(pa, &print, format);
				else if (*format == 's')
					percent_s(pa, &print);
				else if (*format == 'd' || *format == 'i')
					percent_d(pa, &print, format);
				else if (*format == 'D' || *format == 'u')
					percent_D(pa, &print, format);
				else if (*format == 'U')
					percent_U(pa, &print);
				else if (*format == 'p')
					percent_p(pa, &print);
				else if (*format == 'o')
					percent_o(pa, &print, format);
				else if (*format == 'O')
					percent_O(pa, &print);
				else if (*format == 'c')
					format = percent_c(pa, &print, format);
				else if(*format == 'x' || *format == 'X')
					format = percent_x(pa, &print, format);
			}
		}
		else
		{
			ft_putchar(*format);
			++print.ret;
		}
		++format;
	}
	va_end(pa);
	return (print.ret);
}
