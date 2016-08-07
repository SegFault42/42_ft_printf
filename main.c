/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdugue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 08:57:36 by rabdugue          #+#    #+#             */
/*   Updated: 2016/08/07 12:59:58 by rabougue         ###   ########.fr       */
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
	ft_putstr("ft_printf(\"%.d\", %.0d, 0, 0)|");
	ret = ft_printf("%.d, %.0d", 0, 0);
	printf("| ret = %d", ret);
	printf("\n");
	ft_putstr("   printf(\"%.d\", %.0d, 0, 0)|");
	ret = printf("%.d, %.0d", 0, 0);
	printf("| ret = %d", ret);
	printf("\n");
	return (0);
}
