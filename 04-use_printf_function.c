#include "main.h"

/**
 * get_size - Determines the data type to cast the argument.
 * @format: Formatted string for printing arguments.
 * @b: List of arguments to be printed.
 * Return: The specified data type.
 */
int get_size(const char *format, int *b)
{
	int curr_b = *b + 1;
	int size = 0;

	if (format[curr_b] == 'l')
		size = S_LONG;
	else if (format[curr_b] == 'h')
		size = S_SHORT;

	if (size == 0)
		*b = curr_b - 1;
	else
		*b = curr_b;

	return (size);
}
