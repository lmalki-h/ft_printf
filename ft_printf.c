/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:29:46 by lmalki-h          #+#    #+#             */
/*   Updated: 2020/02/04 14:40:42 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char		*g_specifiers = "cspdiuxX%";
const char		*g_flags = " -0+#";
const char		*g_intspecifiers = "pdiuxX";

static int		init_struct(t_convert **conv)
{
	if ((*conv = (t_convert *)ft_calloc(1, sizeof(t_convert))) == NULL)
		return (0);
	(**conv).specifier = '0';
	ft_bzero((*conv)->flag, ft_strlen(g_flags));
	(**conv).width = 0;
	(**conv).precision = -1;
	ft_bzero((*conv)->size, 3);
	(**conv).filler_width = SPACE;
	(**conv).filler_precision = SPACE;
	return (1);
}

static void		dispatch(int *len, t_convert *conv, va_list ap)
{
	if ((*conv).specifier == 'c' || (*conv).specifier == '%')
		format_c(conv, len, ap);
	else if ((*conv).specifier == 's')
		format_s(conv, len, ap);
	else if ((*conv).specifier == 'p')
		format_p(conv, len, ap);
	else if ((*conv).specifier == 'x' || (*conv).specifier == 'X')
		format_x(conv, len, ap);
	else if ((*conv).specifier == 'd' || (*conv).specifier == 'i')
		format_di(conv, len, ap);
	else if ((*conv).specifier == 'u')
		format_u(conv, len, ap);
}

static int		parser(int *len, char **fmt, va_list ap)
{
	t_convert *conv;

	if (!init_struct(&conv))
		return (0);
	add_flag(fmt, conv);
	add_width(fmt, conv, ap);
	add_precision(fmt, conv, ap);
	add_size(fmt, conv);
	add_specifier(fmt, conv);
	get_filler(conv);
	dispatch(len, conv, ap);
	free(conv);
	return (1);
}

static int		ft_vfprintf(const char *format, va_list ap)
{
	char	*fmt;
	int		len;

	len = 0;
	fmt = (char *)format;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			parser(&len, &fmt, ap);
		}
		else
		{
			ft_putchar_fd(*fmt, FD);
			fmt++;
			len++;
		}
	}
	return (len);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	va_start(ap, format);
	len = ft_vfprintf(format, ap);
	va_end(ap);
	return (len);
}
