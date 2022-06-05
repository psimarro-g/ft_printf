/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:23:20 by psimarro          #+#    #+#             */
/*   Updated: 2022/03/08 17:23:29 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_left_align(t_print *tab)
{
	tab->wd--;
	while (tab->wd-- > 0)
	{
		if (tab->zero)
			tab->tlen += write(STD_OUT, "0", 1);
		else
			tab->tlen += write(STD_OUT, " ", 1);
	}
}

static void	ft_right_align(t_print *tab)
{
	tab->wd--;
	while (tab->wd-- > 0)
		tab->tlen += write(STD_OUT, " ", 1);
}

void	ft_printf_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	if ((tab->zero || tab->wd) && !tab->dash)
		ft_left_align(tab);
	tab->tlen += write(STD_OUT, &c, 1);
	if (tab->wd && tab->dash)
		ft_right_align(tab);
}
