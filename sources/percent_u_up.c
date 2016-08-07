/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_u_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 05:00:32 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/07 05:00:33 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	percent_u_up(va_list pa, t_printf *print)
{
	unsigned long	u;

	u = va_arg(pa, unsigned long);
	ft_put_ulong(u);
	if (ft_strlen(ft_ultoa(u)) == 20)
		print->ret += 20;
	else
		print->ret += ft_strlen(ft_ultoa(u));
}
