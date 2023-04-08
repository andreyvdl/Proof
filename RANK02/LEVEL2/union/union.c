#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 0

void	fill_duplicates(char duplicates[128])
{
	size_t	index;

	index = 0;
	while (index < 128)
	{
		duplicates[index] = '\0';
		index++;
	}
}

void	add_to_duplicates(char character, char duplicates[128], int position)
{
	duplicates[position] = character;
}

void	print_string(char *string, char duplicates[128])
{
	int		position;
	size_t	index;

	index = 0;
	position = 0;
	while (string[index] != '\0')
	{
		position = string[index];
		if (string[index] != duplicates[position])
		{
			add_to_duplicates(string[index], duplicates, position);
			write(STDOUT_FILENO, &string[index], 1);
		}
		index++;
	}
}

void	print_argument_without_duplicates(char *string_one, char *string_two)
{
	char	duplicates[128];

	fill_duplicates(duplicates);
	print_string(string_one, duplicates);
	print_string(string_two, duplicates);
}

int	main(int arg_count, char **arg_verb)
{
	if (arg_count == 3)
		print_argument_without_duplicates(arg_verb[1], arg_verb[2]);
	write(STDOUT_FILENO, "\n", 1);
	return (SUCCESS);
}
