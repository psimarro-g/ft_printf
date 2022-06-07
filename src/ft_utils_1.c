#include <ft_printf.h>

void	flags(t_spf *esp)
{
	while (*esp->cnt == '0' || *esp->cnt == '-' || *esp->cnt == '+'
		|| *esp->cnt == ' ' || *esp->cnt == '#')
	{
		if (*esp->cnt == '0')
			esp->zero = 1;
		else if (*esp->cnt == '-')
			esp->left = 1;
		else if (*esp->cnt == ' ')
			esp->space = 1;
		else if (*esp->cnt == '+')
			esp->plus = 1;
		else if (*esp->cnt == '#')
			esp->hash = 1;
		if (esp->zero == 1 && esp->left == 1)
			esp->zero = 0;
		if (esp->plus == 1)
			esp->space = 0;
		esp->cnt++;
	}
}

void	width(t_spf *esp, va_list *argp)
{
	esp->width = star(esp, argp);
	if (!esp->h_w && *esp->cnt != '.')
	{
		esp->width = ft_atoi((const char *)esp->cnt);
		if (esp->width)
			while (*esp->cnt >= '0' && *esp->cnt <= '9')
				esp->cnt++;
		esp->h_w = 1;
	}
	if (esp->width < 0)
	{
		esp->left = 1;
		esp->width = -esp->width;
	}
}

void	precision(t_spf *esp, va_list *argp)
{
	if (*esp->cnt == '.')
	{
		esp->h_p = 1;
		esp->cnt++;
		esp->prcn = star(esp, argp);
		if (!esp->prcn)
		{
			esp->prcn = ft_atoi((const char *)esp->cnt);
			if (esp->prcn)
				while (*esp->cnt >= '0' && *esp->cnt <= '9')
					esp->cnt++;
		}
		if (esp->prcn < 0)
		{
			esp->n_p = 1;
			esp->prcn = -esp->prcn;
		}
	}
	else
		esp->h_p = 0;
}


void	empty(t_spf *esp)
{
	int		auxcount;

	auxcount = esp->count;
	ft_bzero(esp, sizeof(*esp));
	esp->count = auxcount;
}


int	star(t_spf *esp, va_list *argp)
{
	if (*esp->cnt == '*')
	{
		esp->cnt++;
		if (!esp->h_p)
			esp->h_w = 1;
		return (va_arg(*argp, int));
	}
	return (0);
}
