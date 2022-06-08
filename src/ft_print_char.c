/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:06:40 by psimarro          #+#    #+#             */
/*   Updated: 2022/06/08 17:06:42 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	print_prc_char(t_tprint *tab, va_list *args, char percent)
{
	int		i;
	char	character;

	i = -1;
	if (percent != '%')
		character = va_arg(*args, int);
	else
		character = percent;
	tab->len = 1;
	if (!tab->left)
		while (tab->width-- > tab->len)
			draw_width(tab);
	tab->tlen += write(1, &character, 1);
	if (tab->left)
		while (tab->width-- > tab->len)
			draw_width(tab);
	empty(tab);
}
