/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 01:12:54 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/08 11:42:29 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	struct_is_zero(t_printf *print, const char *format)
{
	if (*format == '0')
		print->zero = 1;
}

void	decr_space_number(t_printf *print)
{
	if (print->negatif == 1)
		--print->space_number;
}

void	decr_precision_zero(t_printf *print, int z)
{
	if (z == 0)
		--print->precision_zero;
}
