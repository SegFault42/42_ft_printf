/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 09:20:41 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/07 18:59:12 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_struct(t_printf *printf)
{
	printf->ret = 0;
	printf->ret_wchar = 0;
	printf->valid = 0;
	printf->space_number = 0;
	printf->negatif = 0;
	printf->negatif_x = 0;
	printf->zero = 0;
	printf->d = 0;
	printf->ok = 0;
	printf->sharp = 0;
	printf->plus = 0;
	printf->space = 0;
	printf->point = 0;
	printf->precision_zero = 0;
	printf->precision_space = 0;
}
