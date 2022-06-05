/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:25:21 by psimarro          #+#    #+#             */
/*   Updated: 2022/03/08 17:25:23 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen_base(int n, int base_len)
{
	int	cnt;

	cnt = !n;
	while (n)
	{
		n /= base_len;
		cnt++;
	}
	return (cnt);
}

int	ft_uintlen_base(unsigned int n, int base_len)
{
	int	cnt;

	cnt = 1;
	while (n >= (unsigned int)base_len)
	{
		n /= (unsigned int)base_len;
		cnt++;
	}
	return (cnt);
}

int	ft_ulonglen_base(unsigned long n, int base_len)
{
	int	cnt;

	cnt = 1;
	while (n >= (unsigned long)base_len)
	{
		n /= base_len;
		cnt++;
	}
	return (cnt);
}

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, ft_strlen(s1) + 1);
	return (p);
}