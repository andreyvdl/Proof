#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 2 || !av[1] || !av[1][0])
		return (write(1, "\n", 1), 0);

	for (size_t i = 0; av[1][i]; i++)
	{
		if (av[1][i] >= 'a' && av[1][i] <= 'z')
		{
			if (av[1][i] == 'z')
				write(1, "a", 1);
			else
			{
				av[1][i] += 1;
				write(1, &av[1][i], 1);
			}
		}
		else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
		{
			if (av[1][i] == 'Z')
				write(1, "Z", 1);
			else
			{
				av[1][i] += 1;
				write(1, &av[1][i], 1);
			}
		}
		else
			write(1, &av[1][i], 1);
	}

	write(1, "\n", 1);
	return (0);
}