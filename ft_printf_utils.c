/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:27:58 by lmalki-h          #+#    #+#             */
/*   Updated: 2020/02/05 19:25:40 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			left_align(char *(*f)(char *, t_convert *, int *),
t_convert *conv, int *len, t_cal *cal)
{
	char	*p;

	if (*f)
		p = f(cal->s, conv, len);
	else
		p = cal->s;
	display_precision(len, conv, (*cal).precision);
	ft_putnstr_fd(p, (*cal).len_s, len);
	display_width(conv, (*cal).size, len);
}

void			display_zero(char *(*f)(char *, t_convert *, int *),
t_convert *conv, int *len, t_cal *cal)
{
	char *p;

	if (*f)
		p = f(cal->s, conv, len);
	else
		p = cal->s;
	display_width(conv, (*cal).size, len);
	display_precision(len, conv, (*cal).precision);
	ft_putnstr_fd(p, (*cal).len_s, len);
}

void			display_space(char *(*f)(char *, t_convert *, int *),
t_convert *conv, int *len, t_cal *cal)
{
	char	*p;

	display_width(conv, (*cal).size, len);
	p = f(cal->s, conv, len);
	display_precision(len, conv, (*cal).precision);
	ft_putnstr_fd(p, (*cal).len_s, len);
}

int				get_width(t_cal *cal, t_convert *conv, char *s)
{
	int		size;

	size = 0;
	size = (*cal).precision + (*cal).len_s;
	if ((*conv).specifier == 'd' || (*conv).specifier == 'i')
		if (contains('+', (*conv).flag) && *s != '-')
			size += 1;
	return (size);
}

int				init_cal(t_cal **cal, t_convert *conv, char *s)
{
	if ((*cal = (t_cal *)ft_calloc(1, sizeof(t_cal))) == NULL)
	{
		free(s);
		return (0);
	}
	(**cal).len_s = get_len(conv, s);
	(**cal).precision = get_precision(conv, (**cal).len_s, s);
	(**cal).size = get_width(*cal, conv, s);
	(**cal).s = s;
	return (1);
}
