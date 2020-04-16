/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:01:31 by lmalki-h          #+#    #+#             */
/*   Updated: 2020/02/06 16:22:47 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*split(char *s, t_convert *conv, int *len)
{
	char	*p;

	p = s;
	if (contains('#', (*conv).flag) && ft_strncmp(s, "0\0", 2))
	{
		ft_putnstr_fd(s, 2, len);
		p = &s[2];
	}
	return (p);
}

static char		*build_hex(va_list ap, t_convert *conv)
{
	uintmax_t	n;
	char		*s;

	n = get_unumber(ap, conv);
	s = ft_itohex(n);
	if (contains('#', (*conv).flag) && ft_strncmp(s, "0", 1))
		s = ft_strjoinfree("0x", s, 2);
	return (s);
}

static void		hashtag_flag(t_cal *cal, t_convert *conv)
{
	if ((*conv).precision > 0 && (*conv).width > 0)
	{
		(*cal).precision += 2;
		(*cal).size += 2;
	}
}

int				format_x(t_convert *conv, int *len, va_list ap)
{
	char			*s;
	t_cal			*cal;

	s = build_hex(ap, conv);
	if (!init_cal(&cal, conv, s))
		return (0);
	if ((*conv).specifier == 'X')
		capitalize(s);
	if (contains('#', (*conv).flag) && ft_strncmp(s, "0\0", 2))
		hashtag_flag(cal, conv);
	if (contains('-', (*conv).flag))
		left_align(split, conv, len, cal);
	else
	{
		if (contains(ZERO, (*conv).flag))
			display_zero(split, conv, len, cal);
		else
			display_space(split, conv, len, cal);
	}
	free(cal);
	free(s);
	return (1);
}
