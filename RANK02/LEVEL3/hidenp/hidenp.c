#include <unistd.h>

void	is_hidden(char *str1, char *str2);

int	main(int argc, char **argv)
{
	if (argc == 3)
		is_hidden(argv[1], argv[2]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}

void	is_hidden(char *to_find, char *str)
{
	while (*str != '\0')
	{
		if (*to_find == '\0')
		{
			write(STDOUT_FILENO, "1", 1);
			return ;
		}
		else if (*to_find == *str)
			to_find++;
		str++;
	}
	if (*to_find == '\0')
		write(STDOUT_FILENO, "1", 1);
	else
		write(STDOUT_FILENO, "0", 1);
}
