#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 2 || !av[1] || !av[1][0])
		return (write(1, "\n", 1), 0);
	
	size_t i = 0;

	while (av[1][i] == 32 || av[1][i] == 9)
		i++;
	while (av[1][i] && av[1][i] != 32 && av[1][i] != 9)
	{
		write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}