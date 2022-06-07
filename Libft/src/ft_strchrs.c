

#include <libft.h>

char	*ft_strchrs(const char *str, char *set)
{
	int	i;

	while (*str)
	{
		i = 0;
		while (set[i])
		{
			if (*str == set[i])
				return ((char *)str);
			i++;
		}
		str++;
	}
	return (0);
}
