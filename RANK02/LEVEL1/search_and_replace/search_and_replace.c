#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char *string)
{
	size_t	index;

	index = 0;
	if (string == NULL)
		return (0);
	while (string[index] != '\0')
		index++;
	return (index);
}

void	print_new_line_and_exit(void)
{
	write(STDOUT_FILENO, "\n", 1);
	exit(0);
}

void	validator(char *string, char *to_find, char *substitute)
{
	if (string == NULL || string[0] == '\0')
		print_new_line_and_exit();
	if (to_find == NULL || ft_strlen(to_find) > 1)
		print_new_line_and_exit();
	if (substitute == NULL || ft_strlen(substitute) > 1)
		print_new_line_and_exit();
}

void	search_and_replace(char *string, char to_find, char substitute)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == to_find)
			string[index] = substitute;
		index++;
	}
}

void	print_string(char *string)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
	{
		write(STDOUT_FILENO, &string[index], 1);
		index++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		validator(argv[1], argv[2], argv[3]);
		search_and_replace(argv[1], argv[2][0], argv[3][0]);
		print_string(argv[1]);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
