#include <ft_printf.h>

static void	draw_before(t_spf *esp)
{
	if (esp->width < esp->len && esp->zero && esp->plus && !esp->negative)
	{
		esp->count += write(1, "+", 1);
		esp->plus--;
	}
	if (esp->width > esp->len && !esp->h_p && esp->zero && esp->plus
		&& !esp->negative)
	{
		esp->count += write(1, "+", 1);
		esp->plus--;
	}
	if (esp->width < esp->len && esp->zero && esp->space && !esp->negative
		&& !esp->plus)
	{
		esp->count += write(1, " ", 1);
		esp->space--;
	}
	if (esp->width > esp->len && !esp->h_p && esp->zero && esp->space
		&& !esp->negative && !esp->plus)
	{
		esp->count += write(1, " ", 1);
		esp->space--;
	}
}

static void	draw_after(t_spf *esp, char *nn, char c)
{
	if (esp->negative)
		esp->count += write(1, "-", 1);
	if (esp->plus && !esp->negative)
		esp->count += write(1, "+", 1);
	if (esp->space && !esp->negative && !esp->plus)
		esp->count += write(1, " ", 1);
	if (!(esp->h_w && esp->zero && !esp->h_p))
		hash(esp, c, nn);
}

void	sign_draw(t_spf *esp, int k, char *nn, char c)
{
	if (k)
		draw_before(esp);
	else if (!k)
		draw_after(esp, nn, c);
}

static void	sign_negative(t_spf *esp, char **nn)
{
	if (is_negative(esp, nn) && (!esp->h_p || esp->n_p) && esp->zero
		&& esp->negative--)
	{
		esp->space = 0;
		esp->count += write(1, "-", 1);
	}
	if (esp->negative)
		esp->space = 0;
}

void	sign(t_spf *esp, char **nn, char c)
{
	sign_negative(esp, nn);
	if (esp->h_w && esp->zero && !esp->h_p)
		hash(esp, c, *nn);
	if (esp->plus && esp->width > esp->len && !esp->negative && esp->h_p
		&& esp->prcn == 0 && **nn != '0')
		esp->width--;
	else if (esp->plus && esp->width > esp->len && !esp->negative && !esp->h_p)
		esp->width--;
	else if (esp->plus && esp->width > esp->len && !esp->negative
		&& esp->h_p && esp->prcn > 0)
		esp->width--;
	if (esp->space && esp->width > esp->len && !esp->plus && !esp->negative
		&& esp->h_p && esp->prcn == 0 && **nn != '0')
		esp->width--;
	else if (esp->space && esp->width > esp->len && !esp->plus
		&& !esp->negative && !esp->h_p)
		esp->width--;
	else if (esp->space && esp->width > esp->len && !esp->plus
		&& !esp->negative && esp->h_p && esp->prcn > 0)
		esp->width--;
	sign_draw(esp, 1, *nn, c);
}
