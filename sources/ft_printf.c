
#include "./includes/ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list pa;
	int		n;
	char	*s;
	char	c;
	float	f;
	int ret = 0;

	va_start(pa, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*++format == '%')
			{
				ft_putchar('%');
				ret++;
			}
			else if (*++format == 'c')
			{
				c = va_arg(pa, int);
				ft_putchar(c);
				ret++;
			}
			/*switch (*++format) */
			/*{*/
				/*case '%' : ft_putchar('%'); break;*/
				/*case 'c' : [> affichage d'un caractère <]*/
				/*c = va_arg(pa, int);*/
				/*putchar(c);*/
				/*break;*/
				/*case 'd' : [> affichage d'un entier <]*/
				/*n = va_arg(pa, int);*/
				/*printf("%d", n);*/
				/*break;*/
				/*case 'f' : [> affichage d'un float <]*/
				/*f = va_arg(pa, double);    [> !!!!! <]*/
				/*printf("%f", f);*/
				/*break;*/
				/*case 's' : [> affichage d'une chaîne <]*/
				/*s = va_arg(pa, char *);*/
				/*for ( ; *s != '\0'; s++ )*/
				/*putchar( *s );*/
				/*break;*/
			/*} [> end switch <]*/
		}
		else
		putchar( *format );
		format++;
		ret++;
	}
	va_end(pa);
	ft_putnbr(ret);
	return (ret);
}
