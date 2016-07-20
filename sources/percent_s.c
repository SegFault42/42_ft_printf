/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 07:20:36 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/06 07:21:01 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	percent_s(va_list pa, t_printf *print)
{
	char	*s;
	int		space;

	s = va_arg(pa, char*);
	if (s == 0)
	{
		ft_putstr("(null)");
		print->ret += 6;
	}
	else
	{
		space = ft_strlen(s);
		write_space_percent_s(space, print);
		ft_putstr(s);
		write_space_percent_s(space, print);
		print->ret += ft_strlen(s);
	}
}

