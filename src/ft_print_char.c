#include <ft_printf.h>

void	h_prc_char(t_spf *esp, va_list *argp, char percent)
{
	int		i;
	char	character;

	i = -1;
	if (percent != '%')
		character = va_arg(*argp, int);
	else
		 character = percent;
	esp->len = 1;
	if (!esp->left)
		while (esp->width-- > esp->len)
			draw_width(esp);
	esp->count += write(1, &character, 1);
	if (esp->left)
		while (esp->width-- > esp->len)
			draw_width(esp);
	empty(esp);
}
