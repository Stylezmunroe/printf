#include "main.h"

/**
 * get_precision - Compute the precision value for printing
 * @fmt: Formatted string within the wide-character to represent the argument
 * @j: List of arguments to be printed
 * @lst: List of arguments
 *
 * Return: The calculated precision value
 */
int get_precision(const char *fmt, int *j, va_list lst)
{
	int curr_j = *j + 1;
	int precision = -1;

	if (format[curr_j] != '.')
		return (precision);

	precision = 0;

	for (curr_j += 1; format[curr_j] != '\0'; curr_j++)
	{
		if (is_digit(format[curr_j]))
		{
			precision *= 10;
			precision += format[curr_j] - '0';
		}
		else if (format[curr_j] == '*')
		{
			curr_j++;
			precision = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*j = curr_j - 1;

	return (precision);
}
