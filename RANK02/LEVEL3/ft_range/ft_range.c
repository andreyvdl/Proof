#include <stdlib.h>

static void	fill_array(int *array, int start, int end)
{
	if (start == end)
		*array = end;
	else if (start < end)
	{
		while (start < end)
		{
			*array = start;
			array++;
			start++;
		}
		*array = start;
	}
	else
	{
		while (start > end)
		{
			*array = start;
			array++;
			start--;
		}
		*array = start;
	}
}

int	*ft_range(int start, int end)
{
	int			*array;
	long int	size;

	size = end - start;
	if (size < 0)
		size *= -1;
	array = (int *)malloc(sizeof(int) * (size + 1));
	fill_array(array, start, end);
	return (array);
}
