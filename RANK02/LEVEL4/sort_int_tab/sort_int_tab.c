static int	is_sorted(int *tab, unsigned int size)
{
	unsigned int	index;

	index = 0;
	while (index < size)
	{
		if (tab[index] > tab[index + 1])
			return (0);
		index++;
	}
	return (1);
}

static void	put_lowest_here(int *tab, unsigned int size)
{
	int				temp;
	unsigned int	index;

	index = 1;
	while (index < size)
	{
		if (*tab > tab[index])
		{
			temp = *tab;
			*tab = tab[index];
			tab[index] = temp;
		}
		index++;
	}
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	index;

	index = 0;
	while (is_sorted(tab, size) == 0)
	{
		put_lowest_here(&tab[index], size - index);
		index++;
	}
}
