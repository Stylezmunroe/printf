#include "main.h"

/**
 * is_printable - Evaluates char. Is it printable?
 * @c: Char to be evaluated.
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Adds the ASCII code in hexadecimal format to the buffer.
 * @buffer: Array of characters.
 * @i: Index at which to begin appending.
 * @ascii_code: ASCII code to add.
 * Return: 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* Hexadecimal format codes are consistently 2 digits in length */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * it_digit - Checks if the character is a digit.
 * @c: The character to be assessed.
 * Return: 1 if 'c' is a digit, 0 otherwise.
 */
int it_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Converts a number to the specified data type.
 * @num: The number to be cast.
 * @size: The data type to which 'num' is to be cast.
 * Return: The value of 'num' after casting.
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified unsigned data type.
 * @num: The number to be cast.
 * @size: The unsigned data type to which 'num' is to be cast.
 * Return: The value of 'num' after casting.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
