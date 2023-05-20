#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*holder;
	void	*tmp;

	holder = lst;
	while (lst->next != NULL)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			tmp_data = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp_data;
			lst = holder;
		}
		else
			lst = lst->next;
	}
	return (holder);
}
