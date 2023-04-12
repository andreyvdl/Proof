#include <unistd.h>

void	print_bits(unsigned char octet)
{
	short int	shift;

	if (octet == NULL)
		return ;
	shift = 7;
	while (shift > -1)
	{
		if ((octet & 1 << shift) != 0)
			write(STDOUT_FILENO, "1", 1);
		else
			write(STDOUT_FILENO, "0", 1);
		shift--;
	}
}

/* ALTERNATIVE VERSION:
void	print_bits(unsigned char octet)
{
	short int	shift;

	if (octet == NULL)
		return ;
	shift = 0;
	while (shift < 8)
	{
		if ((octet & 128 >> shift) != 0)
			write(STDOUT_FILENO, "1", 1);
		else
			write(STDOUT_FILENO, "0", 1);
		shift++;
	}
}
*/
