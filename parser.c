/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:19:34 by lmalki-h          #+#    #+#             */
/*   Updated: 2020/02/06 17:37:17 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		add_flag(char **fmt, t_convert *conv)
{
	while (contains(**fmt, g_flags))
	{
		if (!contains(**fmt, (*conv).flag))
			add(**fmt, (*conv).flag);
		(*fmt)++;
	}
}

void		add_width(char **fmt, t_convert *conv, va_list ap)
{
	while (ft_isspace(**fmt))
		(*fmt)++;
	if (ft_isdigit(**fmt))
		(*conv).width = ft_patoi(fmt);
	else if (**fmt == STAR)
	{
		(*conv).width = va_arg(ap, int);
		(*fmt)++;
	}
	if ((*conv).width < 0)
	{
		(*conv).width *= -1;
		if (!contains('-', (*conv).flag))
			add('-', (*conv).flag);
	}
}

void		add_precision(char **fmt, t_convert *conv, va_list ap)
{
	while (ft_isspace(**fmt))
		(*fmt)++;
	if (**fmt == PRECISION)
	{
		(*fmt)++;
		if (ft_isdigit(**fmt))
			(*conv).precision = ft_patoi(fmt);
		else if (**fmt == STAR)
		{
			(*conv).precision = va_arg(ap, int);
			(*fmt)++;
		}
		else
			(*conv).precision = 0;
	}
}

void		add_size(char **fmt, t_convert *conv)
{
	while (ft_isspace(**fmt))
		(*fmt)++;
	if (**fmt == 'l')
	{
		(*conv).size[0] = 'l';
		(*fmt)++;
		if (**fmt == 'l')
		{
			(*conv).size[1] = 'l';
			(*fmt)++;
		}
	}
	else if (**fmt == 'h')
	{
		(*conv).size[0] = 'h';
		(*fmt)++;
		if (**fmt == 'h')
		{
			(*conv).size[1] = 'l';
			(*fmt)++;
		}
	}
}

void		add_specifier(char **fmt, t_convert *conv)
{
	while (ft_isspace(**fmt))
		(*fmt)++;
	if (contains(**fmt, g_specifiers))
	{
		(*conv).specifier = **fmt;
		(*fmt)++;
	}
}
