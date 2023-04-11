#include <stdlib.h>

static size_t	ft_strlen(char *string)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
		index++;
	return (index);
}

static void	ft_strcpy(char *destiny, char *source)
{
	size_t	index;

	index = 0;
	while (source[index] != '\0')
	{
		destiny[index] = source[index];
		index++;
	}
	destiny[index] = '\0';
}

char	*ft_strdup(char *src)
{
	char	*duplicate;

	if (src == NULL)
		return (NULL);
	duplicate = NULL;
	duplicate = malloc(ft_strlen(src) + 1);
	if (duplicate == NULL)
		return (duplicate);
	ft_strcpy(duplicate, src);
	return (duplicate);
}
