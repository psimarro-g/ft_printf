
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;

	i = 0;
	if (n)
		while (n--)
			((unsigned char *)s)[i++] = 0;
}
