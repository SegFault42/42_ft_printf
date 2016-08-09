/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 08:57:36 by rabdugue          #+#    #+#             */
/*   Updated: 2016/08/09 15:30:18 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./libft/includes/libft.h"
#include <stdlib.h>
#include <wchar.h>
#include <limits.h>


int	main(void)
{
	int	ret;

	ret = 0;
	ft_putstr("ft_printf(\"%.4S\", \"42\")|");
	ret = ft_printf("%.4S", "42");
	printf("| ret = %d", ret);
	printf("\n");
	ft_putstr("   printf(\"%.4S\", 42)|");
	ret = printf("%.4S", 42);
	printf("| ret = %d", ret);
	printf("\n");
	/*ft_putstr("ft_printf(\"%-15p\", 0)|");*/
	/*ret = ft_printf("%-15p", 0);*/
	/*printf("| ret = %d", ret);*/
	/*printf("\n");*/
	/*ft_putstr("   printf(\"%-15p\", 0)|");*/
	/*ret = printf("%-15p", 0);*/
	/*printf("| ret = %d", ret);*/
	/*printf("\n");*/
	return (0);
}
