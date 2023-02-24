#include <unistd.h>

void	print_case(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	else
		c += 32;
	write(1, &c, 1);
}

int	letter_check(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2 || !av[1] || !av[1][0])
		return (write(1, "\n", 1), 0);

	for (size_t i = 0; av[1][i]; i++)
	{
		if (letter_check(av[1][i]))
			print_case(av[1][i]);
		else
			write(1, &av[1][i], 1);
	}

	write(1, "\n", 1);
	return (0);
}