/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:24:55 by psimarro          #+#    #+#             */
/*   Updated: 2022/03/08 17:24:56 by psimarro         ###   ########.fr       */
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
			print_len = tab->wd;
		else
			print_len = len;
	}
	else
		print_len = len;
	return (print_len);
}

static void	ft_handle_left_align(t_print *tab, int print_len)
{
	tab->wd -= print_len;
	while (tab->wd-- > 0)
		tab->tlen += write(STD_OUT, " ", 1);
}

static void	ft_handle_zeros(t_print *tab, unsigned int n, int print_len)
{
	print_len -= ft_uintlen_base(n, 10);
	while (print_len-- > 0)
		tab->tlen += write(STD_OUT, "0", 1);
}

static void	ft_handle_right_align(t_print *tab, int print_len)
{
	if (!tab->dash)
		return ;
	tab->wd -= print_len;
	while (tab->wd-- > 0)
		tab->tlen += write(STD_OUT, " ", 1);
}

void	ft_printf_uint(t_print *tab)
{
	unsigned int	n;
	unsigned int	pow_ten;
	char			c;
	int				print_len;

	n = va_arg(tab->args, unsigned int);
	pow_ten = 1;
	print_len = ft_get_print_len(tab, ft_uintlen_base(n, 10));
	if (!tab->dash)
		ft_handle_left_align(tab, print_len);
	ft_handle_zeros(tab, n, print_len);
	while (n / pow_ten / 10)
		pow_ten *= 10;
	while (pow_ten)
	{
		c = n / pow_ten + '0';
		tab->tlen += write(STD_OUT, &c, 1);
		n %= pow_ten;
		pow_ten /= 10;
	}
	ft_handle_right_align(tab, print_len);
}
