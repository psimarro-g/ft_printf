

#include "libft.h"

long long int	ft_ndigit(long long int n, long long unsigned int base)
{
	long long unsigned int		n_dgt;

	n_dgt = 0;
	if (n < 0)
		n = -n;
	else if (n == 0)
		return (1);
	while (n)
	{
		n_dgt++;
		n = n / base;
	}
	return (n_dgt);
}
