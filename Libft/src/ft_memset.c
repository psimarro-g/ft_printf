

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;

	i = 0;
	while (len--)
		((unsigned char *)b)[i++] = c;
	return (b);
}
