/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 21:24:52 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/07 05:52:49 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

typedef struct	s_printf
{
	int			ret;
	int			space_number;
	int			valid;
}				t_printf;
/*
** percent_percent.c
*/
const char		*percent_percent(const char *format, t_printf *printf);
const char		*percent_percent_neg(const char *format, t_printf *printf);
const char		*if_percent(const char *format, t_printf *printf);

int				ft_printf(const char *format, ...);
int				count_space(const char *format);
void			percent_s(va_list pa, t_printf *print);

#endif
