/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 21:24:52 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/05 03:27:03 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../../libft/includes/libft.h"

typedef struct	s_printf
{
	char		*cp_format;
	int			ret;
}				t_printf;

/*
** percent_percent.c
*/
const char		*percent_percent(const char *format, t_printf *printf);
const char		*percent_percent_neg(const char *format, t_printf *printf);
const char		*if_percent(const char *format, t_printf *printf);

int				ft_printf(const char *format, ...);

#endif
