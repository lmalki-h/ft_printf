/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:23:41 by lmalki-h          #+#    #+#             */
/*   Updated: 2020/02/05 19:14:47 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putnstr_fd(char *s, int size, int *len)
{
	int i;

	i = 0;
	while (i < size && s[i])
	{
		ft_putchar_fd(s[i], FD);
		i++;
	}
	(*len) += i;
}

void		display_precision(int *len, t_convert *conv, int precision)
{
	int		i;

	i = 0;
	if (contains((*conv).specifier, g_intspecifiers))
		(*conv).filler_precision = ZERO;
	while (i < precision)
	{
		ft_putchar_fd((*conv).filler_precision, FD);
		i++;
	}
	(*len) += i;
}

void		display_width(t_convert *conv, int size, int *len)
{
	int		i;
	int		width;

	i = 0;
	if ((*conv).width > 0 && (*conv).width > size)
	{
		width = (*conv).width - size;
		while (i < width)
		{
			ft_putchar_fd((*conv).filler_width, FD);
			i++;
		}
		(*len) += i;
	}
}
