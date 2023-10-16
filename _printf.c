#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Prints output according to a format
 * @format: The format string containing conversion specifiers
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int j, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list lst;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lst, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &j);
			width = get_width(format, &j, lst);
			precision = get_precision(format, &j, lst);
			size = get_size(format, &j);
			++j;
			printed = handle_print(format, &j, lst, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(lst);

	return (printed_chars);
}

/**
 * print_buffer - Displays the content of the buffer if it is present
 * @buffer: An array of characters
 * @buff_ind: Index @ wich the next char should be aded, reps the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
