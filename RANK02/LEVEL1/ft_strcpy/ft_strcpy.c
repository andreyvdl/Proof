char	*ft_strcpy(char *s1, char *s2)
{
	for (int i = 0; s2[i]; i++)
		s1[i] = s2[i];
	return (s1);
}