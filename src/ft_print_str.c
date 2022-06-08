#include <ft_printf.h>

void	h_string(t_tprint *tab, va_list *args)
{
	int		i;
	char	*str;

	i = -1;
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	tab->len = ft_strlen(str);
	if (tab->prcn < tab->len && (tab->prcn != 0 || tab->h_p) && !tab->n_p)
		tab->width += tab->len - tab->prcn;
	if (!tab->left)
		while (tab->width-- > tab->len)
			draw_width(tab);
	if (!tab->h_p || tab->prcn != 0 || tab->n_p)
		while (str[++i] && (i < tab->prcn || tab->prcn == 0 || tab->n_p))
			tab->count += write(1, &str[i], 1);
	if (tab->left)
		while (tab->width-- > tab->len)
			draw_width(tab);
	empty(tab);
}
