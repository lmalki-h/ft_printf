/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:32:01 by lmalki-h          #+#    #+#             */
/*   Updated: 2020/02/06 18:12:43 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*print_sign(char *s, t_convert *conv, int *len)
{
	int		sign;
	char	*p;

	sign = issign(s);
	p = s;
	if (sign == 1)
	{
		ft_putnstr_fd(s, 1, len);
		p = &s[1];
	}
	else if (contains('+', (*conv).flag) && sign == 0)
	{
		ft_putchar_fd('+', FD);
		(*len)++;
	}
	return (p);
}

static void		space_flag(t_cal *cal, int *len)
{
	ft_putnstr_fd(" ", 1, len);
	(*cal).size += 1;
}

static char		*build_di(va_list ap, t_convert *conv)
{
	intmax_t	n;
	char		*s;

	n = get_number(ap, conv);
	s = ft_itoa(n);
	return (s);
}

int				format_di(t_convert *conv, int *len, va_list ap)
{
	char	*s;
	t_cal	*cal;

	s = build_di(ap, conv);
	if (!init_cal(&cal, conv, s))
		return (0);
	if (!contains('+', (*conv).flag) && contains(' ', (*conv).flag)
	&& *s != '-')
		space_flag(cal, len);
	if (contains('-', (*conv).flag))
		left_align(print_sign, conv, len, cal);
	else
	{
		if (contains(ZERO, (*conv).flag))
			display_zero(print_sign, conv, len, cal);
		else
			display_space(print_sign, conv, len, cal);
	}
	free(cal);
	free(s);
	return (1);
}
