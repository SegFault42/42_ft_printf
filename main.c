/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 08:57:36 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/06 08:59:40 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./libft/includes/libft.h"
#include <stdio.h>
#include <wchar.h>
#include <limits.h>

int	main(void)
{
	int	ret;

	ret = 0;
	ft_putstr("ft_printf(\"%hU\", \"4294967296\")|");
	ret = ft_printf("%hU", "4294967296");
	printf("| ret = %d", ret);
	printf("\n");
	ft_putstr("   printf(\"%hU\", \"4294967296\")|");
	ret = printf("%hU", "4294967296");
	printf("| ret = %d", ret);
	printf("\n");
	return (0);
}
