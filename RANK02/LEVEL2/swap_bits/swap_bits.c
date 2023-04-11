unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	swaped;

	swaped = '\0';
	swaped += ((octet >> 4) & 0b00001111);
	swaped += ((octet << 4) & 0b11110000);
	return (swaped);
}
