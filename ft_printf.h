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
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
** MACROS
*/
# define FSPECS		"cspdiuxX%"
# define STD_OUT	1
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

typedef struct s_print
{
	va_list	args;
	int		wd;
	int		dot;
	int		dash;
	int		zero;
	int		sharp;
	int		sp;
	int		plus;
	int		tlen;
	int		sign;
	int		is_zero;
	int		perc;
}	t_print;
/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
** MAIN FUNCTIONS
*/
int		ft_printf(const char *format, ...);
void	ft_printf_char(t_print *tab);
void	ft_printf_str(t_print *tab);
void	ft_printf_int(t_print *tab);
void	ft_printf_uint(t_print *tab);
void	ft_printf_ptr(t_print *tab);
void	ft_printf_hex(t_print *tab, char flag);
void	ft_printf_perc(t_print *tab);

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
** UTILS FUNCTIONS
**
** Basic Libc functions - note: some were adapted and thus named with a suffix
** to indicate the nature of the customization.
*/
/*
** FILE: ft_printf_utils.c
*/
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
/*
** FILE: ft_printf_utils_2.c
*/
int		ft_intlen_base(int n, int base_len);
int		ft_uintlen_base(unsigned int n, int base_len);
int		ft_ulonglen_base(unsigned long n, int base_len);
/*
** FILE: ft_printf_utils_3.c
*/
t_print	*ft_initialise_tab(t_print *tab);
t_print	*ft_reset_tab(t_print *tab);

#endif