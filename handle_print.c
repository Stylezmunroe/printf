#include "main.h"
/**
 * handle_print - Handles the printing of argument based on type
 * @fmt: The formatted string to print arguments
 * @lst: List args to be printed.
 * @indx: The index
 * @buffer: The buffer array used for printing.
 * @flags: The active flags used for calculations
 * @width: The width specifier
 * @precision: The precision specifier
 * @size: The size specifier
 * Return: Returns 1 or 2
 */
int handle_print(const char *fmt, int *indx, va_list lst, char buffer[],
	int flags, int width, int precision, int size)
{
	int j, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (j = 0; fmt_types[j].fmt != '\0'; j++)
		if (fmt[*indx] == fmt_types[j].fmt)
			return (fmt_types[j].fn(lst, buffer, flags, width, precision, size));

	if (fmt_types[j].fmt == '\0')
	{
		if (fmt[*indx] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*indx - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*indx);
			while (fmt[*indx] != ' ' && fmt[*ind] != '%')
				--(*indx);
			if (fmt[*indx] == ' ')
				--(*indx);
			return (1);
		}
		unknow_len += write(1, &fmt[*indx], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
