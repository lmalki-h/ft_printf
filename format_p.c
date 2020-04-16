/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:53:53 by lmalki-h          #+#    #+#             */
/*   Updated: 2020/02/05 19:16:30 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		is_null(char **s)
{
	if (*s == NULL)
		*s = "0";
}

void			format_p(t_convert *conv, int *len, va_list ap)
{
	char			*s;
	int				len_s;
	int				precision;
	int				size;

	s = ft_itohex(va_arg(ap, long unsigned int));
	is_null(&s);
	len_s = ft_strlen(s) + 2;
	precision = get_precision(conv, len_s, s);
	size = precision + len_s;
	if (contains('-', (*conv).flag))
	{
		ft_putnstr_fd("0x", 2, len);
		display_precision(len, conv, precision);
		ft_putnstr_fd(s, len_s, len);
		display_width(conv, size, len);
	}
	else
	{
		display_width(conv, size, len);
		ft_putnstr_fd("0x", 2, len);
		display_precision(len, conv, precision);
		ft_putnstr_fd(s, len_s, len);
	}
	free(s);
}
