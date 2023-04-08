#define NULL ((void *)0)

static int	reach_int_min(void)
{
	int	number;

	number = 0;
	while (number < 1)
		number--;
	return (number + 1);
}

int	max(int *tab, unsigned int len)
{
	unsigned int	index;
	int				biggest_number;

	biggest_number = reach_int_min();
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
