#include "main.h"

/**
 * get_width - Compute the width for printing
 * @fmt: The Formatted string used for representing the arguments
 * @j: The List argumnts to be printed.
 * @lst: The list of argumnts.
 *
 * Return: The calculated width.
 */
int get_width(const char *fmt, int *j, va_list lst)
{
	int curr_j;
	int width = 0;

	for (curr_j = *j + 1; format[curr_j] != '\0'; curr_j++)
	{
		if (is_digit(format[curr_j]))
		{
			width *= 10;
			width += format[curr_j] - '0';
		}
		else if (format[curr_j] == '*')
		{
			curr_j++;
			width = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*j = curr_j - 1;

	return (width);
}
