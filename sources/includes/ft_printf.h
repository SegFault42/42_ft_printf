/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 21:24:52 by rabougue          #+#    #+#             */
/*   Updated: 2016/06/28 16:56:32 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../../libft/includes/libft.h"

typedef struct	s_printf
{
	char		*cp_format;
}				t_printf;

/*
** percent_percent.c
*/
int	percent_percent(const char *format, int ret);
int	percent_percent_neg(const char *format, int ret);
int	if_percent(const char *format, int ret);

int	ft_printf(const char *format, ...);

#endif
