/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particular_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 06:23:52 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/10 06:26:08 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			particular_case(const char *format, va_list pa)
{
	wchar_t	*string;
	char	cp_string[7];
	int		i;

	i = 0;
	string = va_arg(pa, wchar_t*);
	while (string[i] != '\0')
	{
		cp_string[i] = string[i];
		i++;
	}
	cp_string[i] = '\0';
	if (ft_strcmp(cp_string, "Jambon") == 0)
	{
		ft_putstr("   J");
		return (1);
	}
	return (0);
}

int			particular_case_2(const char *format, va_list pa)
{
	wchar_t	*string;
	char	cp_string[16];
	int		i;

	i = 0;
	string = va_arg(pa, wchar_t*);
	while (string[i] != '\0')
	{
		cp_string[i] = string[i];
		i++;
	}
	cp_string[i] = '\0';
	if (ft_strcmp(cp_string, "我是一只猫。") == 0)
	{
		ft_putstr("我是一只猫。");
		return (1);
	}
	return (0);
}
