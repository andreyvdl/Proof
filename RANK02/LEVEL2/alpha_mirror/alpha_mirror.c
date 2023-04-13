#include <unistd.h>
#define UPPER 1
#define LOWER -1
#define NON_ALPHA 0
#define ALPHA_LOW "zyxwvutsrqponmlkjihgfedcba"
#define ALPHA_UPP "ZYXWVUTSRQPONMLKJIHGFEDCBA"

static int	which_case(char character)
{
	if (character >= 'a' && character <= 'z')
		return (LOWER);
	else if (character >= 'A' && character <= 'Z')
		return (UPPER);
	return (NON_ALPHA);
}

static void	print_mirror(char character, char *alpha)
{
	if (alpha[0] == 'z')
		write(STDOUT_FILENO, &alpha[character - 97], 1);
	else
		write(STDOUT_FILENO, &alpha[character - 65], 1);
}

static void	mirror(char *string)
{
	size_t	index;

	if (string == NULL)
		return ;
	index = 0;
	while (string[index] != '\0')
	{
		if (which_case(string[index]) == UPPER)
			print_mirror(string[index], ALPHA_UPP);
		else if (which_case(string[index]) == LOWER)
			print_mirror(string[index], ALPHA_LOW);
		else
			write(STDOUT_FILENO, &string[index], 1);
		index++;
	}
}

int	main(int argcount, char **argverb)
{
	if (argcount == 2)
		mirror(argverb[1]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
