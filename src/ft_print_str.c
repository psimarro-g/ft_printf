#include <ft_printf.h>

void	h_string(t_spf *esp, va_list *argp)
{
	int		i;
	char	*str;

	i = -1;
	str = va_arg(*argp, char *);
	if (!str)
		str = "(null)";
	esp->len = ft_strlen(str);
	if (esp->prcn < esp->len && (esp->prcn != 0 || esp->h_p) && !esp->n_p)
		esp->width += esp->len - esp->prcn;
	if (!esp->left)
		while (esp->width-- > esp->len)
			draw_width(esp);
	if (!esp->h_p || esp->prcn != 0 || esp->n_p)
		while (str[++i] && (i < esp->prcn || esp->prcn == 0 || esp->n_p))
			esp->count += write(1, &str[i], 1);
	if (esp->left)
		while (esp->width-- > esp->len)
			draw_width(esp);
	empty(esp);
}
