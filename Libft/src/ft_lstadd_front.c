

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	if (!*alst)
	{
		new->next = 0;
		*alst = new;
	}
	else
	{
		new->next = *alst;
		*alst = new;
	}
}
