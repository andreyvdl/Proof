#include "ft_list.h"
#include <stdlib.h>

static void	prev_is_null_free(t_list **begin_list, t_list **curr)
{
	*begin_list = (*curr)->next;
	free((*curr)->data);
	free(*curr);
	*curr = *begin_list;
}

static void	prev_exist_free(t_list **curr, t_list **prev)
{
	(*prev)->next = (*curr)->next;
	free((*curr)->data);
	free(*curr);
	*curr = (*prev)->next;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*curr;
	t_list	*prev;

	if (begin_list == 0x0 || *begin_list == 0x0 || cmp == 0x0)
		return ;
	curr = *begin_list;
	prev = NULL;
	while (curr != NULL)
	{
		if (cmp(curr->data, data_ref) == 0)
		{
			if (prev == NULL)
				prev_is_null_free(begin_list, &curr);
			else
				prev_exist_free(&curr, &prev);
			continue ;
		}
		prev = curr;
		curr = curr->next;
	}
}
