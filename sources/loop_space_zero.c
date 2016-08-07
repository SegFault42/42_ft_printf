/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_space_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 17:13:52 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/07 17:16:35 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	loop_space(t_printf *print)
{
	while (print->precision_space-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
}
