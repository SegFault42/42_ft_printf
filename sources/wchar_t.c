/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 02:30:30 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/09 06:33:54 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	one_octet(t_printf *print, wchar_t *s, int i)
{
	print->ret_wchar++;
	ft_putchar(s[i]);
}

static void	two_octet(t_printf *print, wchar_t *s, int i)
{
	print->ret_wchar += 2;
	ft_putchar(192 | (s[i] >> 6));
	ft_putchar(128 | (s[i] & 63));
}

static void	three_octet(t_printf *print, wchar_t *s, int i)
{
	print->ret_wchar += 3;
	ft_putchar(224 | (s[i] >> 12));
	ft_putchar(128 | ((s[i] >> 6) & 63));
	ft_putchar(128 | (s[i] & 63));
}

static void	four_octet(t_printf *print, wchar_t *s, int i)
{
	print->ret_wchar += 4;
	ft_putchar(240 | (s[i] >> 18));
	ft_putchar(128 | ((s[i] >> 12) & 63));
	ft_putchar(128 | ((s[i] >> 6) & 63));
	ft_putchar(128 | (s[i] & 63));
}

void		percent_s_up_normal_1(t_printf *print, wchar_t *s, int i)
{
	if (s[i] > 0 && s[i] < 128)
		one_octet(print, s, i);
	else if (s[i] < 2048)
		two_octet(print, s, i);
	else if (s[i] < 65536)
		three_octet(print, s, i);
	else if (s[i] < 1114112)
		four_octet(print, s, i);
}
