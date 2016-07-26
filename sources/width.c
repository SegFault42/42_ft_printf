#include "../includes/ft_printf.h"
#include <stdio.h>

void	write_space_hex(int space, t_printf *print)
{
	if (print->negatif == 1)
		print->negatif = 0;
	else
	{
		char *string = ft_itoa(space);
		print->space_number -= ft_strlen(string) - 1;
		if (print->space_number > 0)
		{
			if (print->zero == 1 && print->d < 0)
				ft_putchar('-');
			while (print->space_number--)
			{
				if (print->zero == 1)
					ft_putchar('0');
				else
					ft_putchar(' ');
				print->ret++;
			}
		}
	}
}

void	write_space_percent_s(int space, t_printf *print)
{
	if (print->negatif == 1)
		print->negatif = 0;
	else
	{
		char *string = ft_itoa(space);
		print->space_number -= space;
		if (print->space_number > 0)
		{
			if (print->zero == 1 && print->d < 0)
				ft_putchar('-');
			while (print->space_number--)
			{
				if (print->zero == 1)
					ft_putchar('0');
				else
					ft_putchar(' ');
				print->ret++;
			}
		}
	}

}

void	write_space_int(int space, t_printf *print)
{
	if (print->negatif == 1)
		print->negatif = 0;
	else
	{
		char *string = ft_itoa(space);
		print->space_number -= ft_strlen(string);
		if (print->plus == 1)
			print->space_number--;
		if (print->space_number > 0)
		{
			if (print->zero == 1 && print->d < 0)
				ft_putchar('-');
			while (print->space_number--)
			{
				if (print->zero == 1)
					ft_putchar('0');
				else
					ft_putchar(' ');
				print->ret++;
			}
		}
	}
}

void	write_space_wchar(t_printf *print)
{
	if (print->negatif == 1)
		print->negatif = 0;
	else
	{
		print->ret_wchar = print->space_number - print->ret_wchar;
		if (print->ret_wchar > 0)
		{
			while (print->ret_wchar--)
			{
				if (print->zero == 1)
					ft_putchar('0');
				else
					ft_putchar(' ');
				print->ret++;
			}
		}
	}
}

void	write_space_int_other(t_printf *print, const char *format)
{
	if (print->negatif == 1)
		print->negatif = 0;
	else
	{
		/*print->space_number -= ft_strlen(format);*/
		print->space_number--;
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
		print->precision_space -= ft_strlen(test) + 2;
		if (print->precision_space > 0)
		{
			while (print->precision_space--)
			{
				if (print->zero == 1)
					ft_putchar('0');
				else
					ft_putchar(' ');
				print->ret++;
			}
		}
	}
}

