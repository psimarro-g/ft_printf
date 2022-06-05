/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:24:12 by psimarro          #+#    #+#             */
/*   Updated: 2022/03/08 17:24:14 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_print_len(t_print *tab, int len)
{
	int	print_len;

	if (tab->dot)
	{
		if (tab->dot > len)
			print_len = tab->dot;
		else
			print_len = len;
	}
	else if (tab->zero)
	{
		if (tab->wd > len)
			print_len = tab->wd - 2;
		else
			print_len = len - 2;
	}
	else
		print_len = len;
	return (print_len);
}

static void	ft_handle_left_align(t_print *tab, int print_len)
{
	if (tab->dash)
		return ;
	tab->wd -= print_len + 2;
	while (tab->wd-- > 0)
		tab->tlen += write(STD_OUT, " ", 1);
}

static void	ft_handle_zeros(t_print *tab, unsigned long n, int print_len)
{
	print_len -= ft_ulonglen_base(n, 16);
	while (print_len-- > 0)
		tab->tlen += write(STD_OUT, "0", 1);
}

static void	ft_handle_right_align(t_print *tab, int print_len)
{
	if (!tab->dash)
		return ;
	tab->wd -= print_len + 2;
	while (tab->wd-- > 0)
		tab->tlen += write(STD_OUT, " ", 1);
}

void	ft_printf_ptr(t_print *tab)
{
	unsigned long	n;
	unsigned long	pow;
	char			c;
	int				print_len;

	n = va_arg(tab->args, unsigned long);
	print_len = ft_get_print_len(tab, ft_ulonglen_base(n, 16));
	ft_handle_left_align(tab, print_len);
	tab->tlen += write(STD_OUT, "0x", 2);
	ft_handle_zeros(tab, n, print_len);
	pow = 1;
	while (n / pow / 16)
		pow *= 16;
	while (pow)
	{
		c = n / pow;
		if (c >= 0 && c <= 9)
			c += '0';
		else
			c += 87;
		tab->tlen += write(STD_OUT, &c, 1);
		n %= pow;
		pow /= 16;
	}
	ft_handle_right_align(tab, print_len);
}
