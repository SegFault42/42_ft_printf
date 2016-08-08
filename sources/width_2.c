/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:07:11 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/08 16:07:52 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	write_space_hex_1(t_printf *print)
{
	if (print->sharp == 1)
	{
		print->space_number -= 2;
		if (print->zero == 1)
		{
			ft_putstr("0x");
			print->ret += 2;
		}
	}
}

void		write_space_hex(long space, t_printf *print)
{
	char	*string;

	if (print->negatif == 1)
		print->negatif = 0;
	else
	{
		string = ft_hexa_ltoa(space, 0);
		print->space_number -= ft_strlen(string);
		write_space_hex_1(print);
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
