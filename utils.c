#include "main.h"

/**
 * is_printable - Checks if a character is printable
 * @c: The character to be evaluated.
 * Return: 1 if character is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Add ASCII char in hexadeci format to buffer
 * @buffer: Array of characters to append to.
 * @j: Index at which to start appending
 * @ascii_code: ASCII CODE to convert to hexadecimal
 * Return: Always returns 3
 */
int append_hexa_code(char ascii_code, char buffer[], int j)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexadecimal format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[j++] = '\\';
	buffer[j++] = 'x';

	buffer[j++] = map_to[ascii_code / 16];
	buffer[j] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Checks if the given char is a digit
 * @c: The character to be evaluated
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Changes the size of the number
 * @num: The number to be changed
 * @size: The desired size of the number
 * Return: The modified number with the specified size
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
 * convert_size_unsgnd - Converts a number to a specified size
 * @num: The number to be converted
 * @size: The size indicating the type of conversion
 * Return: The converted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
