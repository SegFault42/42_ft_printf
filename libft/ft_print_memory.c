/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 07:59:12 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/08 01:30:29 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_hex_mem(unsigned char *addr, size_t size)
{
	size_t		i;
	static char	hex[] = "0123456789abcdef";

	i = -1;
	while (++i < 16)
	{
		if (i < size)
		{
			ft_putchar(hex[(int)addr[i] / 16]);
			ft_putchar(hex[(int)addr[i] % 16]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2)
			ft_putchar(' ');
	}
}

void	print_raw_mem(unsigned char *addr, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
	{
		if (addr[i] > 31 && addr[i] < 127)
			ft_putchar(addr[i]);
		else
			ft_putchar('.');
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t	i;

	i = 0;
	while (size > 16)
	{
		print_hex_mem((unsigned char*)(addr + i), 16);
		print_raw_mem((unsigned char*)(addr + i), 16);
		ft_putchar('\n');
		size -= 16;
		i += 16;
	}
	print_hex_mem((unsigned char*)(addr + i), size);
	print_raw_mem((unsigned char*)(addr + i), size);
	ft_putchar('\n');
}
