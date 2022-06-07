

#include "libft.h"
#include <stdio.h>

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*aux;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (0);
	i = 0;
	aux = ft_trimf(s, (char []){c, '\0'});
	j = ft_nsep(aux, c);
	ret = ft_calloc(sizeof(char *), j + 2);
	if (!ret)
		return (0);
	j = 0;
	while (aux[j])
	{
		start = j;
		while (aux[j] != c && aux[j])
			j++;
		ret[i++] = ft_substr(aux, start, j - start);
		if (aux[j])
			j++;
	}
	return (ret);
}
