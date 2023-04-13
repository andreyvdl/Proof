#include <stddef.h>

int	is_power_of_2(unsigned int n)
{
	size_t	multiplied;

	if (n == 0)
		return (0);
	else if (n == 1 || n == 2)
		return (1);
	multiplied = 2;
	while (multiplied < n)
		multiplied *= 2;
	if (multiplied == n)
		return (1);
	return (0);
}
