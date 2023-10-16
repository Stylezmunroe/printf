#include "main.h"

/**
 * get_size - Determines the casting size for the arguments
 * @fmt: The Formatted str in wch to print d arg
 * @j: The List arg to be printed.
 *
 * Return: The calculated Precision.
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
