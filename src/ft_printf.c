/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:25:06 by psimarro          #+#    #+#             */
/*   Updated: 2022/03/08 17:25:08 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*get_esp(const char **format)
{
	char	*aux;

	if (!ft_strchrs(*format + 1, FSPECS))
		return (0);
	aux = ft_substr(*format, 1, ft_strlen(*format)
			- ft_strlen(ft_strchrs(*format + 1, FSPECS)));
	*format = *format + ft_strlen(aux);
	return (aux);
}

void	charge_strc(t_spf *esp, va_list *argp)
{
	flags(esp);
	width(esp, argp);
	precision(esp, argp);
}

void	h_trigger(const char **format, va_list *argp, t_spf *esp)
{
	char	*t_end;
	char	*aux;

	if (**format == '%' && *format + 1)
	{
		esp->cnt = get_esp(format);
		aux = esp->cnt;
		if (esp->cnt)
			charge_strc(esp, argp);
		if (!esp->cnt)
			return ;
		t_end = ft_strchrs(esp->cnt, FSPECS);
		if (*t_end == 'c' || *t_end == '%')
			h_prc_char(esp, argp, *t_end);
		else if (*t_end == 's')
			h_string(esp, argp);
		else if (*t_end == 'i' || *t_end == 'd' || *t_end == 'x'
			|| *t_end == 'X' || *t_end == 'u' || *t_end == 'p')
			h_any_n(esp, argp, *t_end);
		free(aux);
	}
	else if (!(*format + 1))
		return;
	else
		esp->count += write(1, *format, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	t_spf	*esp;
	int		cnt;

	esp = (t_spf *)ft_calloc(1, sizeof(t_spf));
	va_start(argp, format);
	while (*format)
	{
		h_trigger(&format, &argp, esp);
		format++;
	}
	va_end(argp);
	cnt = esp->count;
	free(esp);
	return (cnt);
}
