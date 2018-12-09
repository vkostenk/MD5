/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:54:28 by vkostenk          #+#    #+#             */
/*   Updated: 2018/09/11 14:10:16 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>

/*
** structs to hold all parsing shit
*/
typedef struct				s_flag
{
	int						minus;
	int						plus;
	int						space;
	int						zero;
	int						hashtag;
}							t_flag;

typedef struct				s_format
{
	t_flag					flag;
	int						width;
	int						precision;
	int						dot;
	char					*length;
	char					specifier;
	int						len;
}							t_format;

/*
** for array of functions that will be caled depends from specifier
*/
typedef char				*(*t_fun)(t_format*, va_list*);
int							ft_printf(char *format, ...);
/*
** Parse all shit %[flags][width][.precision][length]specifier
*/
t_format					*ft_get_all_flags(char *format,
		va_list *arg, size_t *i);
t_flag						ft_get_first_flag(char *format, size_t *i);
int							ft_get_width(char *format, size_t *i,
		va_list *arg, t_format *allflagsstruct);
int							ft_get_precision(char *format,
		size_t *i, va_list *arg, t_format *allflagsstruct);
char						*ft_get_length(char *format, size_t *i);
/*
** some kind of logic
*/
int							ft_type(t_format *format, va_list *arg);
t_fun						ft_function(char c);
/*
** taking care of flags
*/
long long					ft_convertflags(t_format *format, va_list *arg);
unsigned long long			ft_uconvertflags(t_format *format, va_list *arg);
/*
** printing functions
*/
char						*ft_print_str(t_format *format, va_list *arg);
char						*ft_print_nbr(t_format *format, va_list *arg);
char						*ft_print_char(t_format *format, va_list *arg);
char						*ft_print_hex(t_format *format, va_list *arg);
char						*ft_print_octal(t_format *format, va_list *arg);
char						*ft_print_ptr(t_format *format, va_list *arg);
char						*ft_print_wstr(t_format *format, va_list *arg);
size_t						ft_wstrlen(unsigned *str);
char						*ft_print_unbr(t_format *format, va_list *arg);
int							ft_uint_count(long long n);

#endif
