#include <ft_printf.h>

char	*is_pnt_or_h(t_spf *esp, long long unsigned int n, char c)
{
	char	*aux_ret;

	if (c == 'p' || (n != 0 && esp->hash))
		esp->width -= 2;
	if (c == 'X')
		aux_ret = ft_itoa_base(n, 16, EX_BASE_UP);
	else
		aux_ret = ft_itoa_base(n, 16, EX_BASE);
	return (aux_ret);
}

int	is_negative(t_spf *esp, char **nn)
{
	if (**nn == '-')
	{
		esp->negative = 1;
		(*nn)++;
		if (esp->width > esp->prcn && esp->h_p)
		{
			esp->len--;
			esp->width--;
		}
		else if (esp->width == esp->prcn && esp->h_p)
			esp->len--;
		if (esp->h_p && esp->prcn > esp->width)
			esp->prcn++;
		return (1);
	}
	else
		return (0);
}
