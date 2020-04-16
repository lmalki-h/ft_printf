/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:20:48 by lmalki-h          #+#    #+#             */
/*   Updated: 2020/02/06 16:22:19 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		is_null(char **s)
{
	if (*s == NULL)
		*s = "(null)";
}

static int		get_precision_s(char *s, t_convert *conv)
{
	int len_s;

	len_s = 0;
	if (s && *s)
	{
		len_s = ft_strlen(s);
		if ((*conv).precision > -1 && (*conv).precision < len_s)
			return ((*conv).precision);
	}
	return (len_s);
}

void			format_s(t_convert *conv, int *len, va_list ap)
{
	char	*s;
	int		size;

	s = (char *)va_arg(ap, char *);
	is_null(&s);
	size = get_precision_s(s, conv);
	if (contains('-', (*conv).flag))
	{
		ft_putnstr_fd(s, size, len);
		display_width(conv, size, len);
	}
	else
	{
		display_width(conv, size, len);
		ft_putnstr_fd(s, size, len);
	}
}
