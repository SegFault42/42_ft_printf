/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 07:20:36 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/04 06:15:41 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	percent_s(va_list pa, t_printf *print)
{
	char	*s;
	int		space;
	int		i;

	i = 0;
	s = va_arg(pa, char*);
	if (s == '\0')
	{
		if (print->space_number > 0)
		{
			while (print->space_number-- > 0)
			{
				ft_putchar('0');
				++print->ret;
			}
		}
		else
		{
			ft_putstr("(null)");
			print->ret += 6;
		}
	}
	else
	{
		space = ft_strlen(s);
		if (print->zero == 1)
		{
			print->space_number -= space;
			while (print->space_number-- > 0)
			{
				ft_putchar('0');
				++print->ret;
			}
		}
		if (print->precision_zero == 0 && print->precision_space > 0)
		{
			if (s != '\0' && print->point == 0)
				print->precision_space -= ft_strlen(s);
			while (print->precision_space-- != 0)
			{
				ft_putchar(' ');
				++print->ret;
			}
			if (s != '\0' && print->point == 0)
			{
				/*print->precision_space -= ft_strlen(s);*/
				ft_putstr(s);
				print->ret += ft_strlen(s);
			}
				return ;
		}
		else if (print->precision_space > print->precision_zero)
		{
			if (space < print->precision_zero)
				print->precision_space -= space;
			else
				print->precision_space -= print->precision_zero;
			while (print->precision_space-- != 0)
			{
				ft_putchar(' ');
				print->ret++;
			}
		}
		else if (print->precision_space < print->precision_zero)
		{
			if (space < print->precision_space)
			{
				print->precision_space -= space;
				while (print->precision_space-- != 0)
				{
					ft_putchar(' ');
					print->ret++;
				}
			}
		}
		else if (print->precision_zero > 0)
		{
			if (print->precision_zero < ft_strlen(s))
				print->precision_space -= print->precision_zero;
			else if (print->precision_zero > ft_strlen(s))
				print->precision_space -= ft_strlen(s);
		}
		if (print->precision_space > 0)
			write_space_percent_s(space, print);
		if (print->precision_zero > 0 && space > print->precision_zero)
			while (print->precision_zero != 0)
			{
				ft_putchar(s[i++]);
				print->precision_zero--;
				++print->ret;
			}
		else
		{
			ft_putstr(s);
			print->ret += ft_strlen(s);
		}
		if (print->precision_space > 0)
			write_space_percent_s(space, print);
	}
}

