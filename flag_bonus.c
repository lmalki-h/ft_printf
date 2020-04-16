/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:50:43 by lmalki-h          #+#    #+#             */
/*   Updated: 2020/02/06 15:55:17 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t			get_ccast(va_list ap, t_convert *conv)
{
	wchar_t		c;

	if (!ft_strncmp((*conv).size, "l", 1))
		c = va_arg(ap, long int);
	else if (!ft_strncmp((*conv).size, "h", 1))
		c = (char)va_arg(ap, int);
	else
		c = (char)va_arg(ap, int);
	return (c);
}

intmax_t		get_unumber(va_list ap, t_convert *conv)
{
	intmax_t	n;

	if (!ft_strncmp((*conv).size, "ll", 2))
		n = va_arg(ap, unsigned long long int);
	else if (!ft_strncmp((*conv).size, "l", 1))
		n = va_arg(ap, long unsigned int);
	else if (!ft_strncmp((*conv).size, "hh", 2))
		n = (unsigned char)va_arg(ap, unsigned int);
	else if (!ft_strncmp((*conv).size, "h", 1))
		n = (unsigned short)va_arg(ap, unsigned int);
	else
		n = va_arg(ap, unsigned int);
	return (n);
}

intmax_t		get_number(va_list ap, t_convert *conv)
{
	intmax_t	n;

	if (!ft_strncmp((*conv).size, "ll", 2))
		n = va_arg(ap, long long int);
	else if (!ft_strncmp((*conv).size, "l", 1))
		n = va_arg(ap, long int);
	else if (!ft_strncmp((*conv).size, "hh", 2))
		n = va_arg(ap, int);
	else if (!ft_strncmp((*conv).size, "h", 1))
		n = (short int)va_arg(ap, int);
	else
		n = va_arg(ap, int);
	return (n);
}
