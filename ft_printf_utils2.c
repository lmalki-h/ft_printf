/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:11:03 by lmalki-h          #+#    #+#             */
/*   Updated: 2020/02/04 11:14:54 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		get_filler(t_convert *conv)
{
	if (contains('0', (*conv).flag) && !contains('-', (*conv).flag))
		(*conv).filler_width = ZERO;
	if (contains((*conv).specifier, g_intspecifiers))
	{
		if ((*conv).precision > -1 && contains(ZERO, (*conv).flag))
		{
			replace('0', 'c', (*conv).flag);
			(*conv).filler_width = SPACE;
		}
	}
}

int			get_len(t_convert *conv, char *s)
{
	int len;

	if ((*conv).precision == 0 && !ft_strncmp(s, "0", 1))
		len = 0;
	else
		len = ft_strlen(s);
	return (len);
}

int			get_size(int len_s, t_convert *conv)
{
	int size;

	size = 0;
	if (contains((*conv).specifier, g_intspecifiers))
	{
		if ((*conv).precision < len_s)
			size = len_s;
		else
			size = (*conv).precision;
	}
	return (size);
}

int			issign(char *s)
{
	if (s[0] == '-')
		return (1);
	return (0);
}

int			get_precision(t_convert *conv, int len_s, char *s)
{
	int		precision;
	int		sign;

	sign = issign(s);
	precision = 0;
	if ((*conv).precision >= len_s)
		precision = (*conv).precision - (len_s - sign);
	return (precision);
}
