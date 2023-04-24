`#incluide "main.h"
/**
 * convert_c - Converts arguments to unsigned char and
 * stores it to a buffer.
 *
 * @args: va_list pointing to the argument
 * @output: A buffer_t struct containing
 * @flags: Flag modifiers
 * @width: A width modifier
 * @precision: A precision modifier
 * @length: A length modifier
 *
 * Return: The number of bytes stored
 */
unsigned int convert_c(va_list args, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char length)
{
	char b;
	unsigned int r = 0;
	(void)precision;
	(void)length;

	b = va_arg(args, int);
	r += print_width(output, r, flags, width);
	r += _memcpy(output, &c, 1);
	r += print_neg_width(output, r, flags, width);

	return (r);
}

/**
 * convert_percent - Stores a percent sign to
 * buffer
 *
 * @args: va_list pointing to the argument to be converted.
 * @output: buffer_t struct containing a character array.
 * @flags: Flag modifiers
 * @width: A width modifier
 * @precision: A precision modifier
 * @length: A length modifier
 *
 * Return: The number of bytes stored to the buffer (always 1)
 */
unsigned int convert_percent(va_list args, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char length)
{
	char percent = '%';
	unsigned int r = 0;

	(void)args;
	(void)precision;
	(void)length;

	r += print_width(output, r, flags, width);
	r += _memcpy(output, &percent, 1);
	r += print_neg_width(output, r, flags, width);
	return (r);
}

/**
 * convert_p - Converts the address of an argument to hex and
 * stores it to a buffer contained in a struct.
 *
 * @args: va_list pointing to the argument to be converted.
 * @output: buffer_t struct containing a character array.
 * @flags: Flag modifiers.
 * @width: width modifier.
 * @precision: precision modifier.
 * @length: length modifier.
 *
 * Return: The number of bytes
 */
unsigned int convert_p(va_list args, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char length)
{
	char *null = "(nil)";
	unsigned long int address;
	unsigned int r = 0;
	(void)length;

	address = va_arg(args, unsigned long int);

	if (address == '\0')

		return (_memcpy(output, null, 5));

	flags |= 32;

	r += convert_ubase(output, address, "0123456789abcdef",
			flags, width, precision);
	r += print_neg_width(output, ret, flags, width);

	return (ret);
}
