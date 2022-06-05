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

void	ft_printf_perc(t_print *tab)
{
	char	c;

	c = '%';
	if ((tab->zero || tab->wd) && !tab->dash)
		ft_left_align(tab);
	tab->tlen += write(STD_OUT, &c, 1);
	if (tab->wd && tab->dash)
		ft_right_align(tab);
}