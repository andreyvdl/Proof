#define NULL ((void *)0)

int	ft_strcmp(char *s1, char *s2)
{
	int	indx;

	if (s1 == NULL && s2 == NULL)
		return (0);
	else if (s1 == NULL)
		return (-1);
	else if (s2 == NULL)
		return (1);
	indx = 0;
	while (s1[indx] != '\0' && s2[indx] != '\0' && s1[indx] == s2[indx])
		indx++;
	return (s1[indx] - s2[indx]);
}
