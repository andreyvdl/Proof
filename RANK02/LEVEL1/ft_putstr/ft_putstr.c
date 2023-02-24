#include <unistd.h>

void	ft_putstr(char *str)
{
	if (!str || !str[0])
		return ;

	for (size_t i = 0; str[i]; i++)
		write(1, &str[i], 1);
}