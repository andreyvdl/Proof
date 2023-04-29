#include <unistd.h>

void	print_space(char *str);
void	print_str(char *str);

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_str(argv[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}

void	print_str(char *str)
{
	while (*str != '\0')
	{
		while ((*str == ' ' || *str == '\t') && *str != '\0')
			str++;
		while (*str != ' ' && *str != '\t' && *str != '\0')
		{
			write(STDOUT_FILENO, str, 1);
			str++;
		}
		if (*str == ' ' || *str == '\t')
			print_space(str);
	}
}

void	print_space(char *str)
{
	while ((*str == ' ' || *str == '\t') && *str != '\0')
		str++;
	if (*str != '\0')
		write(STDOUT_FILENO, " ", 1);
}
