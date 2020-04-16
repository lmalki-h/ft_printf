/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:40:34 by lmalki-h          #+#    #+#             */
/*   Updated: 2020/02/04 10:38:46 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# define FD 			1
# define PRECISION 		'.'
# define STAR 			'*'
# define SPACE 			' '
# define ZERO 			'0'

extern const char		*g_specifiers;
extern const char		*g_flags;
extern const char		*g_intspecifiers;
typedef struct			s_convert
{
	char				specifier;
	char				flag[6];
	int					width;
	int					precision;
	char				size[3];
	char				filler_width;
	char				filler_precision;
}						t_convert;

typedef struct			s_cal
{
	int					precision;
	int					len_s;
	int					size;
	char				*s;
}						t_cal;

int						ft_printf(const char *format, ...);
void					add_flag(char **fmt, t_convert *conv);
void					add_width(char **fmt, t_convert *conv, va_list ap);
void					add_precision(char **fmt, t_convert *conv, va_list ap);
void					add_size(char **fmt, t_convert *conv);
void					add_specifier(char **fmt, t_convert *conv);
void					get_filler(t_convert *conv);
void					format_c(t_convert *conv, int *len, va_list ap);
void					format_s(t_convert *conv, int *len, va_list ap);
void					format_p(t_convert *conv, int *len, va_list ap);
int						format_di(t_convert *conv, int *len, va_list ap);
int						format_x(t_convert *conv, int *len, va_list ap);
int						format_u(t_convert *conv, int *len, va_list ap);
void					ft_putnstr_fd(char *s, int size, int *len);
void					display_width(t_convert *conv, int size, int *len);
void					display_precision(int *len, t_convert *conv, int len_s);
int						get_precision(t_convert *conv, int len_s, char *s);
int						init_cal(t_cal **cal, t_convert *conv, char *s);
void					left_align(char *(*f)(char *, t_convert *, int *),
t_convert *conv, int *len, t_cal *cal);
void					display_zero(char *(*f)(char *, t_convert *, int *),
t_convert *conv, int *len, t_cal *cal);
void					display_space(char *(*f)(char *, t_convert *, int *),
t_convert *conv, int *len, t_cal *cal);
intmax_t				get_unumber(va_list ap, t_convert *conv);
intmax_t				get_number(va_list ap, t_convert *conv);
int						get_width(t_cal *cal, t_convert *conv, char *s);
int						get_len(t_convert *conv, char *s);
int						get_size(int len_s, t_convert *conv);
int						issign(char *s);
char					*print_sign(char *s, t_convert *conv, int *len);
wchar_t					get_ccast(va_list ap, t_convert *conv);
char					*split(char *s, t_convert *conv, int *len);
void					free_conv(t_convert *conv);
#endif
