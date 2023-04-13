unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	reversed;
	int				shift;

	shift = 0;
	while (shift < 8)
	{
		if ((octet >> shift & 1) != 0)
			reversed += 1;
		reversed <<= 1;
		shift++;
	}
	return (reversed);
}
