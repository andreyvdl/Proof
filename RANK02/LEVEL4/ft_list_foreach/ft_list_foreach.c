#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*temp;

	if (begin_list == 0x0 || f == 0x0)
		return ;
	temp = begin_list;
	while (temp != 0x0)
	{
		(*f)(temp->data);
		temp = temp->next;
	}
}
