#include <stddef.h>
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

char	*ft_strpbrk(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	while (s1[index] != '\0')
	{
		if (is_part(s1[index], s2) == TRUE)
			return ((char *)&(s1[index]));
		index++;
	}
	return (NULL);
}
