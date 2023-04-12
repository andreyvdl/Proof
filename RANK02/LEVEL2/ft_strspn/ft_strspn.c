#include <stddef.h> //needed for the size_t
#define TRUE 1
#define FALSE 0

static int	is_part(char character, const char *reference)
{
	size_t	index;

	index = 0;
	while (reference[index] != '\0')
	{
		if (reference[index] == character)
			return (TRUE);
		index++;
	}
	return (FALSE);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0' && is_part(s[size], accept) == TRUE)
		size++;
	return (size);
}
