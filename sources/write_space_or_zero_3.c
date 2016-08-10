/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_space_or_zero_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 09:23:09 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/10 09:27:43 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	loop_zero_no_ret(t_printf *print)
{
	print->ret += print->space_number;
	while (print->space_number-- > 0)
		ft_putchar('0');
}
