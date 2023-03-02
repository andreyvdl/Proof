#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 2 || !av[1] || !av[1][0])
		return (write(1, "\n", 1), 0);

	size_t	i = -1;
	size_t	rep = 0;

	while (av[1][++i])
	{
		rep = 0;
		if (av[1][i] >= 'a' && av[1][i] <= 'z')
		{
			while (av[1][i] - rep > 'a' - 1)
			{
				write(1, &av[1][i], 1);
				rep++;
			}
		}
		else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
		{
			while (av[1][i] - rep > 'A' - 1)
			{
				write(1, &av[1][i], 1);
				rep++;
			}
		}
		else
			write(1, &av[1][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}