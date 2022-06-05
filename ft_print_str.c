/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:24:45 by psimarro          #+#    #+#             */
/*   Updated: 2022/03/08 17:24:47 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_handle_dot(t_print *tab, size_t print_len)
{
	if (print_len > (size_t)tab->dot)
		print_len = tab->dot;
	return (print_len);
}

static void	ft_left_align(t_print *tab, size_t print_len)
{
	tab->wd -= print_len;
	while (tab->wd-- > 0)
	{
		if (tab->zero)
			tab->tlen += write(STD_OUT, "0", 1);
		else
			tab->tlen += write(STD_OUT, " ", 1);
	}
}

static void	ft_right_align(t_print *tab, size_t print_len)
{
	tab->wd -= print_len;
	while (tab->wd-- > 0)
		tab->tlen += write(STD_OUT, " ", 1);
}

void	ft_printf_str(t_print *tab)
{
	char	*s;
	int		i;
	size_t	print_len;

	i = 0;
	s = va_arg(tab->args, char *);
	if (!s && ++i)
		s = ft_strdup("(null)");
	print_len = ft_strlen(s);
	if (tab->dot)
		print_len = ft_handle_dot(tab, print_len);
	if ((tab->zero || tab->wd) && !tab->dash)
		ft_left_align(tab, print_len);
	tab->tlen += write(STD_OUT, s, print_len);
	if (tab->wd && tab->dash)
		ft_right_align(tab, print_len);
	if (i)
		free(s);
}
