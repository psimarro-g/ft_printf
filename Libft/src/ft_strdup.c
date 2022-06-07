

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*aux;
	int		i;

	i = -1;
	aux = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!aux)
		return (0);
	while (s[++i])
		aux[i] = s[i];
	return (aux);
}
