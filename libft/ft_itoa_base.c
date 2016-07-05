/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 05:35:23 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/05 05:36:34 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(long nb, int base)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char	ft_char(long nb)
{
	if (nb < 10)
		return (nb + '0');
	return (nb + 'a' - 10);
}

char	*ft_itoa_base(int value, int base)
{
	long	nb;
	int		neg;
	char	*str;
	int		len;

	nb = value;
	neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		if (base == 10)
			neg = 1;
	}
	len = ft_len(nb, base) + neg;
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = ft_char(nb % base);
		nb /= base;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
