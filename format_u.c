/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:46:10 by lmalki-h          #+#    #+#             */
/*   Updated: 2020/02/04 11:13:26 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*build_u(va_list ap, t_convert *conv)
{
	uintmax_t	n;
	char		*s;

	n = get_unumber(ap, conv);
	s = ft_utoa(n);
	return (s);
}

int				format_u(t_convert *conv, int *len, va_list ap)
{
	char	*s;
	t_cal	*cal;

	s = build_u(ap, conv);
	if (!init_cal(&cal, conv, s))
		return (0);
	if ((*cal).precision > 0)
		(*conv).filler_width = SPACE;
	if (contains('-', (*conv).flag))
		left_align(NULL, conv, len, cal);
	else
		display_zero(NULL, conv, len, cal);
	free(s);
	free(cal);
	return (1);
}
