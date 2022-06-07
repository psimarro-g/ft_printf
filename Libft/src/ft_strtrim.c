

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	sz;

	if (!s1 || !set)
		return (0);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	sz = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[sz]) && sz)
		sz--;
	return (ft_substr((char *)s1, 0, sz + 1));
}
