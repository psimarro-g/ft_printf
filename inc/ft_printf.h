/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:26:03 by psimarro          #+#    #+#             */
/*   Updated: 2022/03/08 17:26:05 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
** HEADERS
*/
# include <libft.h>
# include <stdarg.h>
# include <stdio.h>
/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
** MACROS
*/
# define FSPECS		"%cdisxXpu"
# define STD_OUT	1
# define EX_BASE "0123456789abcdefghijklmnopqrstuvwxyz"
# define EX_BASE_UP "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
** STRUCT DECLARATIONS
*/
/*
** FORMAT SPECIFIER STRUCT
**
** .set:	stores all collected format specifiers.
** .spe_c:	specifier character - i.e. variable type (ex.: %c %s %p %d %i).
** .pad_c:	padding character - could be eiter ' ' (default) or '0' ('0' flag).
** .minus:	'-' flag - left-justifies within the given field width; right
**			justification is the default.
** .plus:	'+' flag - preceeds positive numbers with the plus sign; by default,
**			only negative numbers are preceeded with a '-' sign.
** .space:	' ' flag - a blank space is inserted before unsigned values.
** .hash:	'#' flag - for %o %x %X, preceeds not null values with 0, 0x or 0X
**			respectively; for %a %A %e %E %f %F %g %G, prints decimal point
**			even if no more digits follow. By default, if no digits follow, no
**			decimal point is printed.
** .width:	min number of characters to be printed, with blank space padding if
**			value is shorter than width.
** .point: '1' if precision is given, '0' if not.
** .precision: for %d %i %o %u %x %X, min number of digits to be printed, with
**			with 0 padding if value is shorter than precision; for %a %A %e %E
**			%f %F, number of digits to be printed after the decimal point (by
**			default, this is 6); for %g %G, max number of significants digits
**			to be printed; for %s, max number of characters to be printed (by
**			default, all characters are printed until '\0'); note: '.' = '.0'.
** .length:	modifies the length of the data type as follows:
**				| %d %i (int)	| %u %o %x %X (unsigned int)| %n (int*)		|
**			'l'	| long int		| unsigned long int			| long int*		|
**			'll'| long long int	| unsigned long long int	| long long int*|
**			'h'	| short int		| unsigned short int		| short int*	|
**			'hh	| signed char	| unsigned char				| signed char*	|
** Reference: http://www.cplusplus.com/reference/cstdio/printf/
*/

typedef struct s_spf
{
	char			*cnt;
	int				zero;
	int				left;
	int				width;
	int				count;
	int				h_p;
	int				prcn;
	int				len;
	int				n_p;
	int				h_w;
	int				negative;
	int				plus;
	int				space;
	int				hash;
}	t_spf;
/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
** MAIN FUNCTIONS
*/
int				ft_printf(const char *format, ...);

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
** UTILS FUNCTIONS
*/

void			precision(t_spf *esp, va_list *argp);
void			draw_width(t_spf *esp);
void			h_prc_char(t_spf *esp, va_list *argp, char percent);
void			h_any_n(t_spf *esp, va_list *argp, char c);
void			flags(t_spf *esp);
void			draw_precision(t_spf *esp);
void			width(t_spf *esp, va_list *argp);
void			empty(t_spf *esp);
void			h_string(t_spf *esp, va_list *argp);
int				star(t_spf *esp, va_list *argp);
int				is_negative(t_spf *esp, char **nn);
char			*is_pnt_or_h(t_spf *esp, long long unsigned int n, char c);
void			hash(t_spf *esp, char c, char *nn);
void			sign(t_spf *esp, char **nn, char c);
void			sign_draw(t_spf *esp, int k, char *nn, char c);

#endif