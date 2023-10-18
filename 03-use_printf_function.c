#include "main.h"

/*** For Printing Pointer ***/
/**
 * print_pointer - Prints the value of a pointer variable.
 * @types: List of arguments.
 * @buffer: Print buffer.
 * @flags: Formatting options.
 * @width: Output width.
 * @precision: Decimal places.
 * @size: Data size.
 * Return: Count of printed characters.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[b], BUFF_SIZE - b - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/*** For Printing Non Printable ***/
/**
 * print_non_printable - Prints ASCII codes in hexa for non-printable char
 * @types: List of arguments.
 * @buffer: Print buffer.
 * @flags: Formatting options.
 * @width: Output width.
 * @precision: Decimal places.
 * @size: Data size.
 * Return: Count of printed characters.
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int b = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[b] != '\0')
	{
		if (is_printable(str[b]))
			buffer[b + offset] = str[b];
		else
			offset += append_hexa_code(str[b], buffer, b + offset);

		b++;
	}

	buffer[b + offset] = '\0';

	return (write(1, buffer, b + offset));
}

/*** For Printing Reverse ***/
/**
 * print_reverse - Outputs the reverse of a string.
 * @types: List of arguments.
 * @buffer: Printing buffer.
 * @flags: Formatting options.
 * @width: Output width.
 * @precision: Decimal places.
 * @size: Data size.
 * Return: Count of printed characters.
 */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int x, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (x = 0; str[x]; x++)
		;

	for (x = x - 1; x >= 0; x--)
	{
		char z = str[x];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**** For Printing a String In Rot13 ****/
/**
 * print_rot13string - Outputs the string in ROT13 encoding.
 * @types: List of arguments.
 * @buffer: Printing buffer.
 * @flags: Formatting options.
 * @width: Output width.
 * @precision: Decimal places.
 * @size: Data size.
 * Return: Count of printed characters.
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int b, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (b = 0; str[b]; b++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[b])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[b];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
