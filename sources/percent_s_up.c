#include "../includes/ft_printf.h"

int		count_octet_wchar(wchar_t *s)
{
	int	i;
	int	octet;

	i = 0;
	octet = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			if (s[i] > 0 && s[i] < 128)
				octet++;
			else if (s[i] < 2048)
				octet+=2;
			else if (s[i] < 65536)
				octet+=3;
			else if (s[i] < 1114112)
				octet+=4;
			i++;
		}
		/*printf("<%d>", print->ret_wchar);*/
	}
	return (octet);
}

void	percent_S(va_list pa, t_printf *print)
{
	wchar_t			*s;
	int				i;

	i = 0;
	s = va_arg(pa, wchar_t*);
	if (print->negatif == 0)
	{
		print->ret_wchar = count_octet_wchar(s);
		write_space_wchar(print);
	}
	if (s != NULL)
	{
		while (s[i])
		{
			if (s[i] > 0 && s[i] < 128)
			{
				print->ret_wchar++;
				ft_putchar(s[i]);
			}
			else if (s[i] < 2048)
			{
				print->ret_wchar+=2;
				ft_putchar(192 | (s[i] >> 6));
				ft_putchar(128 | (s[i] & 63));
			}
			else if (s[i] < 65536)
			{
				print->ret_wchar+=3;
				ft_putchar(224 | (s[i] >> 12));
				ft_putchar(128 | ((s[i] >> 6) & 63));
				ft_putchar(128 | (s[i] & 63));
			}
			else if (s[i] < 1114112)
			{
				print->ret_wchar+=4;
				ft_putchar(240 | (s[i] >> 18));
				ft_putchar(128 | ((s[i] >> 12) & 63));
				ft_putchar(128 | ((s[i] >> 6) & 63));
				ft_putchar(128 | (s[i] & 63));
			}
			i++;
		}
		/*write_space_wchar(print);*/
		/*printf("<%d>", print->ret_wchar);*/
	}
				/*printf("d");*/
	else
	{
		ft_putstr("(null)");
		print->ret += 6;
	}
	if (print->negatif == 1)
	{
		print->ret_wchar = count_octet_wchar(s);
		write_space_wchar(print);
		write_space_wchar(print);
	}
	print->ret += count_octet_wchar(s);
}
