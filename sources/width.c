#include "../includes/ft_printf.h"
#include <stdio.h>

void	write_space_int(int space, t_printf *print)
{
	if (print->negatif == 1)
		print->negatif = 0;
	else
	{
		char *string = ft_itoa(space);
		print->space_number -= ft_strlen(string);
		if (print->space_number > 0)
		{
			while (print->space_number--)
			{
				ft_putchar(' ');
				print->ret++;
			}
		}
	}
}

void	write_space_char(char *p, t_printf *print)
{
	if (print->negatif == 1)
		print->negatif = 0;
	else
	{
		char *test = ft_hexa_ltoa((unsigned long long)p, 0);
		print->space_number -= ft_strlen(test) + 2;
		if (print->space_number > 0)
		{
			while (print->space_number--)
			{
				ft_putchar(' ');
				print->ret++;
			}
		}
	}
}

