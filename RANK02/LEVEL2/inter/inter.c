#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 0

void	fill_duplicates(char duplicates[128])
{
	int	index;

	index = 0;
	while (index < 128)
	{
		duplicates[index] = '\0';
		index++;
	}
}

int	exist_on_string_two(char character, char *string)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == character)
			return (TRUE);
		index++;
	}
	return (FALSE);
}

void	add_to_duplicates(char character, char duplicates[128], int position)
{
	duplicates[position] = character;
}

void	print_argument_without_duplicates(char *string_one, char *string_two)
{
	int		position;
	char	duplicates[128];
	size_t	index;

	index = 0;
	position = 0;
	fill_duplicates(duplicates);
	while (string_one[index] != '\0')
	{
		position = string_one[index];
		if (string_one[index] != duplicates[position])
		{
			if (exist_on_string_two(string_one[index], string_two) == TRUE)
			{
				add_to_duplicates(string_one[index], duplicates, position);
				write(STDOUT_FILENO, &string_one[index], sizeof(char));
			}
		}
		index++;
	}
}

int	main(int arg_count, char **arg_verb)
{
	if (arg_count == 3)
		print_argument_without_duplicates(arg_verb[1], arg_verb[2]);
	write(STDOUT_FILENO, "\n", 1);
	return (SUCCESS);
}
