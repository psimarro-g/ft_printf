

#include "libft.h"

long long int	ft_ndigit(long long int n, long long unsigned int base)
{
	long long unsigned int		n_dgt;

	n_dgt = 1;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n >= ft_power(base, n_dgt))
		n_dgt++;
	return (n_dgt);
}
