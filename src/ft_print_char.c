#include <ft_printf.h>

void	h_prc_char(t_tprint *tab, va_list *args, char percent)
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
	tab->count += write(1, &character, 1);
	if (tab->left)
		while (tab->width-- > tab->len)
			draw_width(tab);
	empty(tab);
}
