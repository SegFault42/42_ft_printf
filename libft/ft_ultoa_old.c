/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 23:35:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/09 00:51:26 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"


/*static void	incr(unsigned long *i, unsigned long *res)*/
/*{*/
	/*while (*res != 0)*/
	/*{*/
		/**res = *res / 10;*/
		/**i = *i + 1;*/
	/*}*/
/*}*/

char		*ft_ultoa(unsigned long int n)
{
	int	i;
	unsigned long int	res;
	char			*str;

	i = 0;
	res = n;
	if (res == 0)
		i = 1;
	while (res != 0)
	{
		res = res / 10;
		i = i + 1;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i--)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
