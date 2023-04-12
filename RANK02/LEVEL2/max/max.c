#include <limits.h>

int	max(int *tab, unsigned int len)
{
	unsigned int	index;
	int				biggest_number;

	biggest_number = INT_MIN;
	index = 0;
	if (len == 0 || tab == NULL)
		return (0);
	while (index < len)
	{
		if (biggest_number < tab[index])
			biggest_number = tab[index];
		index++;
	}
	return (biggest_number);
}
