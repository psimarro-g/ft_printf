#include <ft_printf.h>

char	*is_pnt_or_h(t_tprint *tab, long long unsigned int n, char c)
{
	char	*aux_ret;

	if (c == 'p' || (n != 0 && tab->hash))
		tab->width -= 2;
	if (c == 'X')
		aux_ret = ft_itoa_base(n, 16, EX_BASE_UP);
	else
		aux_ret = ft_itoa_base(n, 16, EX_BASE);
	return (aux_ret);
}

int	is_negative(t_tprint *tab, char **nn)
{
	if (**nn == '-')
	{
		tab->negative = 1;
		(*nn)++;
		if (tab->width > tab->prcn && tab->h_p)
		{
			tab->len--;
			tab->width--;
		}
		else if (tab->width == tab->prcn && tab->h_p)
			tab->len--;
		if (tab->h_p && tab->prcn > tab->width)
			tab->prcn++;
		return (1);
	}
	else
		return (0);
}
