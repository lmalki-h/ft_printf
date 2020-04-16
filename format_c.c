/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:53:17 by lmalki-h          #+#    #+#             */
/*   Updated: 2020/02/06 15:43:32 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_c(t_convert *conv, int *len, va_list ap)
{
	char	c;
	int		size;

	if ((*conv).specifier == '%')
		c = '%';
	else
		c = get_ccast(ap, conv);
	size = sizeof(c);
	if (contains('-', (*conv).flag))
	{
		ft_putchar_fd(c, FD);
		(*len)++;
		display_width(conv, size, len);
	}
	else
	{
		display_width(conv, size, len);
		ft_putchar_fd(c, FD);
		(*len)++;
	}
}
