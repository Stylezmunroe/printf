#include "main.h"

/**
 * get_precision - Determines the precision for formatting and printing.
 * @format: The formatted string controlling argument printing.
 * @b: Additional arguments to be printed.
 * @list: The list of arguments.
 * Return: The calculated precision.
 */

int get_precision(const char *format, int *b, va_list list)
{
	int curr_b = *b + 1;
	int precision = -1;

	if (format[curr_b] != '.')
		return (precision);

	precision = 0;

	for (curr_b += 1; format[curr_b] != '\0'; curr_b++)
	{
		if (it_digit(format[curr_b]))
		{
			precision *= 10;
			precision += format[curr_b] - '0';
		}
		else if (format[curr_b] == '*')
		{
			curr_b++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*b = curr_b - 1;

	return (precision);
}
