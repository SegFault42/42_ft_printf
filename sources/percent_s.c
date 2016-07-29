/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 07:20:36 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/29 03:01:40 by rabougue         ###   ########.fr       */
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
	/*if (print->precision_zero > 0 || print->precision_space > 0)*/
		/*put_space_or_zero_s(print, s);*/
	if (s == 0)
	{
		ft_putstr("(null)");
		print->ret += 6;
	}
	else
	{
		/*printf("<%d>", print->precision_zero);*/
		space = ft_strlen(s);
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
		write_space_percent_s(space, print);
	}
}

