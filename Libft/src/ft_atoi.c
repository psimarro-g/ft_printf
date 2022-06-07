

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				s;
	long long int	r;

	s = 1;
	r = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
		s = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
		r = (r + (*nptr++ - 48)) * 10;
	if (s == -1)
		r *= -1;
	if (r == 0)
		return (0);
	return (r / 10);
}
