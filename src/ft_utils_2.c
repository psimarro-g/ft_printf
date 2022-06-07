#include <ft_printf.h>

void	draw_width(t_spf *esp)
{
	if (esp->zero && !esp->prcn && esp->n_p && !esp->left)
		esp->count += write(1, "0", 1);
	else if (esp->zero && esp->n_p && !esp->left)
		esp->count += write(1, "0", 1);
	else if (esp->zero && !esp->h_p && !esp->left)
		esp->count += write(1, "0", 1);
	else
		esp->count += write(1, " ", 1);
}

void	draw_precision(t_spf *esp)
{
	if ((esp->zero || (esp->width && esp->prcn) || esp->h_p) && !esp->n_p)
	{
		esp->count += write(1, "0", 1);
		esp->zero = 1;
	}
	else
		esp->count += write(1, " ", 1);
	if (esp->left && esp->width)
		esp->width--;
}

void	hash(t_spf *esp, char c, char *nn)
{
	if (!(esp->len == 1 && *nn == '0') && esp->hash && (c == 'x' || c == 'X'))
	{
		if (c == 'x')
			esp->count += write(1, "0x", 2);
		else if (c == 'X')
			esp->count += write(1, "0X", 2);
	}
	return ;
}	
