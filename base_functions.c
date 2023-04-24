#include "main.h"
unsigned int convert_sbase(buffer_t *output, long int num, char *base,
unsigned char flags, int wid, int prec);
unsigned int convert_ubase(buffer_t *output,
unsigned long int num, char *base,
unsigned char flags, int wid, int prec);
/**
 * convert_sbase - Converts a signed long to inputted base and stores
 *                the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num:  Signed long to be converted.
 * @base: Pointer to a string containing the base to convert to.
 * @flags: Flag modifiers.
 * @wid:   Width modifier.
 * @prec:  Precision modifier.
 *
 * Return: The number of bytes in buffer.
 */
unsigned int convert_sbase(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	int s;
	char dig, pa = '0';
	unsigned int ret = 1;

	for (s = 0; *(base + s);)
		s++;
	if (num >= s || num <= -s)
		ret += convert_sbase(output, num / s, base,
				flags, wid - 1, prec - 1);
	else
	{
		for (; prec > 1; prec--, wid--)
			ret += _memcpy(output, &pa, 1);

		if (NEG_FLAG == 0)
		{
			pa = (ZERO_FLAG == 1) ? '0' : ' ';

			for (; wid > 1; wid--)
				ret += _memcpy(output, &pa, 1);
		}
	}
	dig = base[(num < 0 ? -1 : 1) * (num % s)];
	_memcpy(output, &dig, 1);
	return (ret);
}

/**
 * convert_ubase - Converts an unsigned long to an inputted base also
 *                 stores the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num:    Unsigned long to be converted.
 * @base:   Pointer to a string containing the base to convert to.
 * @flags:  Flag modifiers.
 * @wid:    Width modifier.
 * @prec:   Precision modifier.
 *
 * Return: The number of bytes the buffer.
 */
unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	unsigned int s, ret = 1;
	char dig, pa = '0', *lead = "0x";

	for (s = 0; *(base + s);)
		s++;

	if (num >= s)
		ret += convert_ubase(output, num / s, base,
				flags, wid - 1, prec - 1);
	else
	{
		if (((flags >> 5) & 1) == 1)
		{
			wid -= 2;
			prec -= 2;
		}
		for (; prec > 1; prec--, wid--)
			ret += _memcpy(output, &pa, 1);

		if (NEG_FLAG == 0)
		{
			pa = (ZERO_FLAG == 1) ? '0' : ' ';

			for (; wid > 1; wid--)
				ret += _memcpy(output, &pa, 1);
		}
		if (((flags >> 5) & 1) == 1)
			ret += _memcpy(output, lead, 2);
	}
	dig = base[(num % s)];
	_memcpy(output, &dig, 1);

	return (ret);
}
