

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*aux;

	aux = (unsigned char *)s;
	while (n--)
		if (*aux++ == (unsigned char)c)
			return (aux - 1);
	return (0);
}
