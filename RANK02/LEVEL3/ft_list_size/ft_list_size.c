#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		size;
	t_list	*temp;

	temp = begin_list;
	size = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
