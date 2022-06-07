

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elmt;

	elmt = (t_list *)ft_calloc(sizeof(*elmt), 1);
	if (!elmt)
		return (0);
	elmt->content = content;
	return (elmt);
}
