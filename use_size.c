#include "main.h"

/**
 * get_size - Evaluate the data type size for typecasting the argument
 * @fmt: The Formatted string used to represent the argument
 * @j: The List of arguments to be printed.
 *
 * Return: The determined data type size (precision)
 */
int get_size(const char *fmt, int *j)
{
	int curr_j = *j + 1;
	int size = 0;

	if (format[curr_j] == 'l')
		size = S_LONG;
	else if (format[curr_j] == 'h')
		size = S_SHORT;

	if (size == 0)
		*j = curr_j - 1;
	else
		*j = curr_j;

	return (size);
}
