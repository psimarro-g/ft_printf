/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:24:02 by psimarro          #+#    #+#             */
/*   Updated: 2022/03/08 17:24:04 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_print_len(t_print *tab, short sign, int len)
{
	int	print_len;

	if (tab->dot)
	{
		if (tab->dot > len)
			print_len = tab->dot + sign + tab->plus;
		else
			print_len = len;
	}
	else if (tab->zero)
	{
		if (tab->wd > len)
			print_len = tab->wd;
		else
			print_len = len;
	}
	else
	{
		print_len = len;
		if (sign)
			print_len++;
	}
	return (print_len);
}

static void	ft_handle_left_align(t_print *tab, int print_len)
{
	tab->wd -= print_len;
	while (tab->wd-- > 0)
		tab->tlen += write(STD_OUT, " ", 1);
}

static void	ft_handle_sign_zeros(t_print *tab, int n, short sign, int print_len)
{
	print_len -= ft_intlen_base(n, 10);
	print_len--;
	if (sign)
		tab->tlen += write(STD_OUT, "-", 1);
	else if (tab->plus)
		tab->tlen += write(STD_OUT, "+", 1);
	else if (tab->sp)
		tab->tlen += write(STD_OUT, " ", 1);
	else
		print_len++;
	while (print_len-- > 0)
		tab->tlen += write(STD_OUT, "0", 1);
}

static void	ft_handle_right_align(t_print *tab, int print_len)
{
	tab->wd -= print_len;
	while (tab->wd-- > 0)
		tab->tlen += write(STD_OUT, " ", 1);
}

void	ft_printf_int(t_print *tab)
{
	int				n;
	short			sign;
	unsigned int	pow_ten;
	char			c;
	int				print_len;

	n = va_arg(tab->args, int);
	pow_ten = 1;
	sign = (n < 0);
	n = (n >= 0) * n - (n < 0) * n;
	print_len = ft_get_print_len(tab, sign, ft_intlen_base(n, 10));
	if (!tab->dash)
		ft_handle_left_align(tab, print_len);
	ft_handle_sign_zeros(tab, n, sign, print_len);
	while (n / pow_ten / 10)
		pow_ten *= 10;
	while (pow_ten)
	{
		c = n / pow_ten + '0';
		tab->tlen += write(STD_OUT, &c, 1);
		n %= pow_ten;
		pow_ten /= 10;
	}
	if (tab->dash)
		ft_handle_right_align(tab, print_len);
}
